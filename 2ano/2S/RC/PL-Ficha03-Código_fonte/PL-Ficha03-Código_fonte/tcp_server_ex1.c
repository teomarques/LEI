/*******************************************************************************
 * SERVIDOR no porto 9000, à escuta de novos clientes.  Quando surgem
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

/* ------ Implementação (declarações) ------ */
// socket -> cria um novo socket
// int socket(int domain, int type, int protocol);
/* domain: 
 *    Domínio no qual o socket será usado
 *    (processos Unix / internet)
 *    (AF_UNIX, AF_INET, AF_INET6, ...)
 * type:
 *    Tipo de ligação (orientada a ligações ou datagrama)
 *    (SOCK_STREAM, SOCK_DGRAM, ...)
 * protocol:
 *    Forma de comunicação (0 para protocolo por omissão,
 *    IPPROTO_TCP para TCP, IPPROTO_UDP para UDP)
 *    Protocolos por default:
 *      Domínio AF_INET e tipo SOCK_STREAM: TCP
 *      Domínio AF_INET e tipo SOCK_DGRAM: UDP
 * DEVOLVE: "Descritor de socket"
*/

// bind -> associa um socket a um determinado endereço, onde:
// int bind(int fd, const struct sockaddr *address, socklen_t address_len);
/*    fd:          descritor de socket
 *    *address:    ponteiro para o endereço associado ao socket
 *    address_len: dimensão da estrutura de dados inducada em <address>
 * devolve 0 para sucesso ou -1 para erro 
*/

// Aguardar pela recepção de ligações.
// int listen(int fd, int backlog);
/* fd:        "Descritor de socket"
 * backlog:   Quantos clientes são mantidos em espera (a aguardar o accept) 
 *            antes de haver recusa de ligação (com a mensagem "Connection Refused")
 * DEVOLVE:   0 para sucesso, -1 para Erro
*/

// Aceita uma ligação.
// int accept(int fdm const struct sockaddr *address, socklent_t* address_len);
/* fd:          "Descritor de socket"
 * sddress:     Estrutura de dados que vai ser preenchida com informação 
 *              sobre a ligação que está a ser estabelecida
 * address_len: Comprimento do buffer <address>. No final da chamada irá 
 *              conter o tamanho (em octetos) da estrutura <address>
 * DEVOLVE:     "Descritor de socket" da ligação aceite, -1 caso erro
*/

/*
void process_client(int fd);
void erro(char *msg);

struct hostent * gethostbyname(const char* name);

struct hostent
{
  char  *h_name;        // nome oficial do host
  char  **h_aliases     // lista de aliases
  int   h_addrtype;     //hostaddrtype (ex.: AF_INET6)
  int   h_length;       // comprimento do endereço
  char  **h_addr_list   // lista de end. terminada com null
}

struct sockaddr_in
{
  short           sin_family;   // AF_INET
  u_short         sin_port;     // porto a associar
  struct in_addr  sin_addr;     // INADDR_ANY = qualquer
  char            sin:zero;     // padding, deixar EM BRANCO  
}

struct in_addr
{
  unsigned long s_addr;
};

*/

void process_client(int client_fd, int client_id, struct sockaddr_in *client_addr);
void erro(char *msg);

int main() 
{
  int fd, client;       // declare file descriptor and socket descriptor for client in "client"
  int client_id = 0;                        // counter for clients (ver vídeo do obsidian de multithreaded connections)
  struct sockaddr_in addr, client_addr;     // Server and client address structures
  int client_addr_size;                     // Size of client address structure

  bzero((void *) &addr, sizeof(addr));      // Clear addr (address) structure
  addr.sin_family = AF_INET;                // set addr family to AF_INET, which is the internet family
  addr.sin_addr.s_addr = htonl(INADDR_ANY); // set server's ip address to any local address (INADDR_ANY)
  addr.sin_port = htons(SERVER_PORT);       // set server's port to SERVER_PORT (9000)
  // htons(): (host to network short) converte um inteiro short sem sinal da ordem de bytes do host para a ordem de bytes da rede

  // create socket and store it's file descriptor in fd (default)
  if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)          erro("na funcao socket");

  // associate the socket with the address and port in addr using bind()
  if ( bind(fd,(struct sockaddr*)&addr, sizeof(addr)) < 0)  erro("na funcao bind");

  // set the socket (by fd - file descriptor) to listen to incoming connections
  if( listen(fd, 5) < 0)                                    erro("na funcao listen");

  client_addr_size = sizeof(client_addr);   // set the client addr size to the size of client_addr structure

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

// Process the client message
/*
  PARAMETERS:
  int client_fd: file descriptor of the client socket
  int client_id: client ID
  struct sockaddr_in *client_addr: client address structure
 */
void process_client(int client_fd, int client_id, struct sockaddr_in *client_addr)
{
  int nread = 0;          // number of bytes read
  char buffer[BUF_SIZE];  // buffer to store the message
  char message[BUF_SIZE]; // declare message array with size BUF_SIZE = 1024

  // Create message with client IP, port and connection count
  // Format the message according to the exercise requirements
  sprintf(message, "Server received connection from (IP:port) %s:%hu; already received %d connections!\n", 
          inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port), client_id);

  do {
    nread = read(client_fd, buffer, BUF_SIZE-1);  // read the message from the client
    buffer[nread] = '\0';                         // add a null character to the end of the message
    if (nread > 0) {
      // Print message received according to the required format in the exercise
      printf("** New message received **\n");
      printf("Client %d connecting from (IP:port) %s:%hu says \"%s\"\n", 
             client_id, inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port), buffer);
      
      // Send response message to client
      write(client_fd, message, strlen(message));
    }
    fflush(stdout);   // Flush the output buffer
  } while (nread > 0);  // Repeat the loop until the message is empty (fullly read)
  
  close(client_fd);   // close the client socket when message is read
}

void erro(char *msg){
  printf("Erro: %s\n", msg);
  exit(-1);
}
