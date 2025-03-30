#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

/* 
alternativa para comunicar o cliente com o servidor (a correr)
é usando o netcat no terminal:
    nc -u 127.0.0.1 9876 
*/

#define BUFLEN 512  // Tamanho do buffer

void erro(char *msg) 
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) 
{
    // sockaddr_in é uma estrutura que contém um endereço de um socket de internet
    struct sockaddr_in si_outra;        // Informações sobre o servidor
    int s, slen = sizeof(si_outra);     // Descritor do socket e tamanho da estrutura
    char buf[BUFLEN];                   // Buffer para recepção de mensagens
    char mensagem[BUFLEN];              // Buffer para envio de mensagens

    // erro
    if (argc != 3) 
    {
        printf("Uso: %s <endereço IP servidor> <porto>\n", argv[0]);
        exit(1);
    }

    /* Cria socket UDP com parâmetros:
        - AF_INET: família de protocolos da internet
        - SOCK_DGRAM: tipo de socket para datagramas (diferente de SOCK_STREAM do TCP)
        - IPPROTO_UDP: protocolo UDP
    */
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)       erro("Erro na criação do socket");

    // Configura estrutura do servidor
    // memset: preenche os primeiros n bytes da área de memória apontada por si_outra com o valor constante 0
    memset((char *) &si_outra, 0, sizeof(si_outra));
    si_outra.sin_family = AF_INET;                  // Família de protocolos da internet
    si_outra.sin_port = htons(atoi(argv[2]));       // Porto do servidor, usa htons para converter para big-endian

    // Converte endereço IP de texto para formato binário
    if (inet_aton(argv[1], &si_outra.sin_addr) == 0)        erro("Endereço IP inválido");

    // Loop para envio de múltiplas mensagens
    while (1) {
        printf("Escreva uma mensagem (ou 'sair' para terminar): ");
        fgets(mensagem, BUFLEN, stdin);

        // Remove quebra de linha
        mensagem[strcspn(mensagem, "\n")] = '\0';

        // Envia a mensagem
        if (sendto(s, mensagem, strlen(mensagem), 0, (struct sockaddr *) &si_outra, slen) == -1)    erro("Erro no sendto");

        // Termina se o usuário digitar "sair"
        if (strcmp(mensagem, "sair") == 0)      break;
    }

    close(s);
    return 0;
}