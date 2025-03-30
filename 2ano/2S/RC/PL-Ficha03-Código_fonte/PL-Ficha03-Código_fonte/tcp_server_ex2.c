/*******************************************************************************
 * SERVIDOR no porto 9000, à escuta de novos clientes. Quando surgem
 * novos clientes os dados por eles enviados são lidos e descarregados no ecran.
 *******************************************************************************/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>

#define SERVER_PORT     9000
#define BUF_SIZE	1024


void process_client(int client_fd, int client_id, struct sockaddr_in *client_addr);
void erro(char *msg);

int main() 
{            
    // ------------ all equal to exercise 1 START ------------

    int fd, client;       // declare file descriptor and socket descriptor for client in "client"
    int client_id = 0;                        // counter for clients (ver vídeo do obsidian de multithreaded connections)
    struct sockaddr_in addr, client_addr;     // server and client address structures
    int client_addr_size;                     // size of client address structure

    bzero((void *) &addr, sizeof(addr));      // clear addr (address) structure
    addr.sin_family = AF_INET;                // set addr family to AF_INET, which is the internet family
    // INADDR_ANY: 0.0.0.0 (IP address of the local machine) - any incoming messages to any of the IP's of the machine will be accepted
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // set server's ip address to any local address (INADDR_ANY)
    addr.sin_port = htons(SERVER_PORT);       // set server's port to SERVER_PORT (9000)
    // htons(): (host to network short) converte um inteiro short sem sinal da ordem de bytes do host para a ordem de bytes da rede

    // create socket and store it's file descriptor in fd (default)
    if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)          erro("na funcao socket");
    
    // associate the socket with the address and port in addr using bind()
    if ( bind(fd,(struct sockaddr*)&addr, sizeof(addr)) < 0)  erro("na funcao bind");

    // set the socket (by fd - file descriptor) to listen to incoming connections
    if( listen(fd, 5) < 0)                                    erro("na funcao listen");

    client_addr_size = sizeof(client_addr);  // set the client addr size to the size of client_addr structure   

    // ------ Implementação (ciclo de espera de novas ligações) ------

    /* 
    * aqui faz-se espera do socket enviado pelo client, quando recebe, dá accept()
    * depois dá read() / write()
    * depois close() da connection
    * volta a iterar o loop para novas conexões
    */
    while (1)
    {
        //clean finished child processes, avoiding zombies
        //must use WNOHANG or would block whenever a child process was working
        while(waitpid(-1,NULL,WNOHANG)>0);  // clean zombies
        
        // after waiting, accept new connection and store the client's address in client_addr
        // client recebe accept() que retorna um novo file descriptor para o socket do cliente
        client = accept(fd,(struct sockaddr *)&client_addr,(socklen_t *)&client_addr_size);
        
        // if the connection was SUCCESSFUL
        if (client > 0)
        {
        client_id++;                // increment ID for new client
        if (fork() == 0) {          // create new CHILD PROCESS
            close(fd);                // close the server socket in the child process
            /* here we call the process client function before ending child process */
            process_client(client, client_id, &client_addr);   // process the client
            exit(0);      // exit the child process
        }
        close(client);    // close the client socket in the parent process
        }
    }
    return 0;
}

// ------------ all equal to exercise 1 END ------------

// Função modificada para o Exercício 2 - process the client messages
/*
    PARAMETERS:
    int client_fd: file descriptor of the client socket
    int client_id: client ID
    struct sockaddr_in *client_addr: client address structure
*/
void process_client(int client_fd, int client_id, struct sockaddr_in *client_addr)
{
  int nread = 0;                        // number of bytes read          
  char buffer[BUF_SIZE];                // buffer to store the message
  char response[BUF_SIZE];              // buffer to store the response
  FILE *file;                           // pointer to file (domain.txt)
  char domain[BUF_SIZE], ip[BUF_SIZE];  // domain and ip buffers
  int found;                            // flag to indicate if domain was found

  // declara mensagem de boas-vindas ao cliente
  char *welcome_msg = "Bem-vindo ao servidor de nomes do DEI. Indique o nome de domínio\n";
  
  // Write strlen(welcome_msg) bytes of buffer welcome_msg to client FD.
  // Return the number written, or -1.
  write(client_fd, welcome_msg, strlen(welcome_msg));

  // Loop para processar múltiplas requisições do cliente
  while (1) 
  {
    nread = read(client_fd, buffer, BUF_SIZE-1);   // store number of bytes read from FD into nread
    if (nread <= 0) break; // Cliente desconectou ou erro
    buffer[nread] = '\0';  // Adiciona terminador de string no final do buffer

    // Remove quebra de linha se presente
    buffer[strcspn(buffer, "\n")] = '\0';

    // Verifica se o cliente deseja sair (se o length de caracteres fora de "SAIR" for 0)
    if (strcmp(buffer, "SAIR") == 0) 
    {
      char *goodbye_msg = "Até logo!\n";    // Mensagem de despedida
      // Escreve strlen(goodbye_msg) bytes do buffer goodbye_msg para o cliente FD.
      // Retorna o número escrito, ou -1.
      write(client_fd, goodbye_msg, strlen(goodbye_msg));
      break; // depois de escrever ao cliente, sai do loop
    }

    // Abre o ficheiro domain.txt para leitura
    file = fopen("domain.txt", "r");
    if (file == NULL) 
    {
      erro("Erro ao abrir ficheiro domain.txt");
    }

    found = 0;
    // Procura o domínio no ficheiro
    while (fgets(response, BUF_SIZE, file)) // fgets vai guardar BYF_SIZE-1 bytes de file em response
    {
      // lê input do ficheiro e verifica se o domínio é igual ao buffer que o usuário digitou
      if (sscanf(response, "%s %s", domain, ip) == 2) 
      {
        if (strcmp(domain, buffer) == 0) {
          found = 1;
          break;
        }
      }
    }
    fclose(file);

    // Prepara a resposta conforme o resultado da busca
    if (found) {
      snprintf(response, BUF_SIZE, "O nome de domínio %s tem associado o endereço IP %s\n", domain, ip);
    } else {
      snprintf(response, BUF_SIZE, "O nome de domínio %s não tem um endereço IP associado\n", buffer);
    }

    // Envia a resposta ao cliente através do socket client_fd (file descriptor do cliente)
    write(client_fd, response, strlen(response));
  }

  close(client_fd);   // Fecha o socket do cliente
}

void erro(char *msg){
  printf("Erro: %s\n", msg);
  exit(-1);
}