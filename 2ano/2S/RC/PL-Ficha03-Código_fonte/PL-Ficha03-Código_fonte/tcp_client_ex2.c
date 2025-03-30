/**********************************************************************
 * CLIENTE liga ao servidor (definido em argv[1]) no porto especificado
 * (em argv[2]), escrevendo a palavra predefinida (em argv[3]).
 * USO: >cliente <enderecoServidor>  <porto>  <Palavra>
 **********************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define BUFF_SIZE 1024

void erro(char *msg);

// ------------ all equal to exercise 1 START ------------

// argc = 4 (com o nome do executable com argv[0])
// argv[1] = endereço do servidor
// argv[2] = número da porta
// argv[3] = mensagem a ser enviada
int main(int argc, char *argv[]) {
  char endServer[100];        // server's IP address
  int fd;                     // file descriptor
  struct sockaddr_in addr;    // Server's address structure containing IP and PORT
  struct hostent *hostPtr;    // Host entry structure containing server's NAME and IP address

  if (argc != 4) {
    printf("cliente <host> <port> <string>\n");
    exit(-1);
  }

  // server address processing
  // copy server's IP address to endServer
  strcpy(endServer, argv[1]);
  // get server's IP address and check if successfull
  if ((hostPtr = gethostbyname(endServer)) == 0) erro("Não consegui obter endereço");

  // address structure processing and setup
  bzero((void *) &addr, sizeof(addr));  // clear addr (address) structure
  addr.sin_family = AF_INET;            // set addr family to AF_INET (AF = Address Family), which is the internet fmaily
  addr.sin_addr.s_addr = *(long *)(hostPtr->h_addr_list[0]);   // set server's IP address
  addr.sin_port = htons((short) atoi(argv[2]));   // set server's port (argv[2] = port number)

  // create socket and store it's file descriptor in fd (default)
  if ((fd = socket(AF_INET,SOCK_STREAM,0)) == -1)               erro("socket");

  // use socket's file descriptor fd to connect (with connect()) to server whose address is in addr
  if (connect(fd,(struct sockaddr *)&addr,sizeof (addr)) < 0)   erro("Connect");

  // ------------ all equal to exercise 1 END ------------

  // Lê a mensagem de boas-vindas do servidor
  char buffer[BUFF_SIZE];
  int nread = read(fd, buffer, BUFF_SIZE-1);  // Lê BUFF_SIZE-1 bytes do socket fd e armazena em buffer
  // Verifica se a leitura foi bem sucedida
  if (nread > 0) 
  {
    buffer[nread] = '\0';
    printf("%s", buffer);
  }

  // Loop para enviar múltiplas consultas
  while (1) {
    // interaction with user
    printf("Introduza o nome de domínio (ou SAIR para terminar): ");
    fgets(buffer, BUFF_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove a quebra de linha

    write(fd, buffer, strlen(buffer) + 1); // Envia o domínio ao servidor

    // Termina se o usuário digitar SAIR
    if (strcmp(buffer, "SAIR") == 0) {
      break;
    }

    // Lê a resposta do servidor
    nread = read(fd, buffer, BUFF_SIZE-1);
    if (nread <= 0) break;
    buffer[nread] = '\0';
    printf("Resposta do servidor: %s\n", buffer);
  }

  close(fd);    
  exit(0);      
}

void erro(char *msg) {
  printf("Erro: %s\n", msg);
  exit(-1);
}