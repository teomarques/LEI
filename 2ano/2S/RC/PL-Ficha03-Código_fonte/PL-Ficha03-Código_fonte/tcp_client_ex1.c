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

// Inicia uma ligação num socket
// int connect(int fd, const struct sockaddr *address, socklen_t address);
/*
 * fd:          "Descritor de socket"
 * address:     Endereço do servidor ao qual se pretende ligar
 * address_len: Dimensão da estrutura <address>
 * DEVOLVE:     0 para ligação estabelecida, -1 no caso 
*/

// stores info about a host (name, IP address, ...)
/* struct hostent
{
  char  *h_name;        // nome oficial do host
  char  **h_aliases     // lista de aliases
  int   h_addrtype;     //hostaddrtype (ex.: AF_INET6)
  int   h_length;       // comprimento do endereço
  char  **h_addr_list   // lista de end. terminada com null
}
*/

// struct hostent * gethostbyname(const char* name);

/*
struct in_addr
{
  unsigned long s_addr;
};
*/ 

// define o endereço do web socket (IP + porta)
/*
struct sockaddr_in
{
  short           sin_family;   // AF_INET
  u_short         sin_port;     // porto a associar
  struct in_addr  sin_addr;     // INADDR_ANY = qualquer
  char            sin:zero;     // padding, deixar EM BRANCO  
}
*/

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

  // create socket and store it's File Descriptor in fd
  if ((fd = socket(AF_INET,SOCK_STREAM,0)) == -1)               erro("socket");
  
  // use socket's file descriptor fd to connect (with connect()) to server whose address is in addr
  if (connect(fd,(struct sockaddr *)&addr,sizeof (addr)) < 0)   erro("Connect");

  // write using file descriptor, message to be sent (in argv[3]) and it's size to the server 
  write(fd, argv[3], 1+strlen(argv[3]));

  // Create a buffer to store the server's response
  char buffer[BUFF_SIZE];
  int nread;
  
  // Read the response from the server
  nread = read(fd, buffer, BUFF_SIZE-1);
    
  // Check if read was successful and only continue if it was
    if(nread > 0)
    {
        // Ensure the response is null-terminated
        buffer[nread] = '\0';

        // Print the response from the server according to the exercise format
        printf("Received from server:\n%s", buffer);
    }
    else if (nread == 0)
    {
        printf("Server disconnected.\n");
    }
    else
    {
        erro("read error");
    }

  close(fd);    // close the socket 
  exit(0);      // exit the program
}

// escrever mensagem de erro
void erro(char *msg) {
  printf("Erro: %s\n", msg);
  exit(-1);
}
