/*******************************************************************************
 * SERVIDOR no porto 9000, à escuta de novos clientes.  Quando surgem
 * novos clientes os dados por eles enviados são lidos e descarregados no ecran.
 *******************************************************************************/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h> //for inet_ntop() convertion of binary to string
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SERVER_PORT     9000
#define BUF_SIZE	1024
#define DOMAIN_FILE "domain.txt"//added for the domaiin ip mapping

int client_count=0;

void process_client(int fd, struct sockaddr_in client_addr);
void erro(char *msg);
char* search_domain(const char *domain);

int main() {
  int fd, client;
  struct sockaddr_in addr, client_addr;
  int client_addr_size;

  bzero((void *) &addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(SERVER_PORT);

  if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	erro("na funcao socket");

  int opt = 1;
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));// to make it reusable

  if ( bind(fd,(struct sockaddr*)&addr,sizeof(addr)) < 0)
	erro("na funcao bind");
  if( listen(fd, 5) < 0)
	erro("na funcao listen");


  printf("Servidor TCP aguardando conexões na porta %d...\n", SERVER_PORT);
  fflush(stdout); // Ensure immediate printing


  client_addr_size = sizeof(client_addr);
  while (1) {
    //clean finished child processes, avoiding zombies
    //must use WNOHANG or would block whenever a child process was working
    while(waitpid(-1,NULL,WNOHANG)>0);
    //wait for new connection
    client = accept(fd,(struct sockaddr *)&client_addr,(socklen_t *)&client_addr_size);
    if (client > 0) {
      client_count++;

      if (fork() == 0) {
        close(fd);
        process_client(client, client_addr);//added the struct here too
        exit(0);
      }
    close(client);
    }
  }
  return 0;
}

void process_client(int client_fd, struct sockaddr_in client_addr)//added struct here
{
	int nread = 0;
	char buffer[BUF_SIZE];
  char response[BUF_SIZE];//added for 2nd ex
  char client_ip[INET_ADDRSTRLEN];

  inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
  int client_port = ntohs(client_addr.sin_port);  

  printf("Client %d connected from IP: %s, Port: %d\n", client_count, client_ip, client_port);
  fflush(stdout);


  /*snprintf(buffer, BUF_SIZE, "Server received connection from (IP:port) %s:%d; already received %d connections!\n",
    client_ip, client_port, client_count);*/ //--> ex1

  write(client_fd, buffer, strlen(buffer));

  do {
    nread = read(client_fd, buffer, BUF_SIZE-1);
    if(nread <= 0) break;
	  buffer[nread] = '\0';
	  printf("%s\n", buffer);
      
	  fflush(stdout);// this was deleted by chatgbt, ensure immediate printing of client

    if(strcmp(buffer, "SAIR") == 0){
      snprintf(response, BUF_SIZE, "Ate logo!\n");
      write(client_fd, response, strlen(response));
      break;
    }

    char *ip = search_domain(buffer);
    
    snprintf(response, BUF_SIZE, "%s\n", ip);

printf("DEBUG: Sending response to client -> %s\n", response);  // ✅ Print the exact message being sent
fflush(stdout);

int bytes_sent = write(client_fd, response, strlen(response));
if (bytes_sent < 0) {
    perror("Error sending response to client");
} else {
    printf("DEBUG: Sent %d bytes to client\n", bytes_sent);
}

    
  } while (nread>0);
	close(client_fd);
  printf("Client %d disconnected.\n", client_count);
  fflush(stdout);
}


char* search_domain(const char *domain){
  static char result[BUF_SIZE];
  FILE *file = fopen(DOMAIN_FILE, "r");

  if(!file){
    snprintf(result, BUF_SIZE, "Erro: Nao foi pssivel abrir o arquivo %s\n", DOMAIN_FILE);
    return result;
  }

  char file_domain[256], file_ip[256];
  while(fscanf(file, "%s %s" , file_domain, file_ip) != EOF){//fscanf for pointer *file
    if(strcmp(domain, file_domain) == 0){
      snprintf(result, BUF_SIZE, "O nome de domini %s tem associado o endereco IP %s", domain, file_ip);
      printf("DEBUG: Returning IP -> %s\n", result);  //  Debugging Output
      fflush(stdout);
      fclose(file);
      return result;
    }

  }

  fclose(file);
  snprintf(result, BUF_SIZE, "O nome de dominio %s não tem um endereço IP associado\n", domain);
  printf("DEBUG: Returning NOT FOUND message -> %s\n", result);  // Debugging Output
  fflush(stdout);
  return result;
}



void erro(char *msg){
	printf("Erro: %s\n", msg);
	exit(-1);
}
