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

void erro(char *msg);

int main(int argc, char *argv[]) {
    char buffer[512];
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);

    if (argc != 4) {
        printf("USO: %s <host> <port> <domain>\n", argv[0]);
        exit(-1);
    }

    // Cria o socket UDP
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        erro("Erro ao criar socket UDP");
    }

    // Obtém o endereço do servidor
    struct hostent *hostPtr;
    if ((hostPtr = gethostbyname(argv[1])) == 0) {
        erro("Erro ao obter endereço do servidor");
    }

    // Configura o endereço do servidor
    bzero((void*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = ((struct in_addr *)(hostPtr->h_addr))->s_addr;
    server_addr.sin_port = htons(atoi(argv[2]));

    // Envia a consulta de domínio para o servidor
    if (sendto(sockfd, argv[3], strlen(argv[3]), 0, (struct sockaddr*)&server_addr, server_len) < 0) {
        erro("Erro ao enviar dados");
    }

    // Recebe a resposta do servidor
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&server_addr, &server_len);
    if (n < 0) {
        erro("Erro ao receber resposta");
    }

    buffer[n] = '\0';  
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}

void erro(char *msg) {
    perror(msg);
    exit(-1);
}
