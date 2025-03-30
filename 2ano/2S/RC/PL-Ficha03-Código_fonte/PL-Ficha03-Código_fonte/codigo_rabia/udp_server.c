#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512   
#define PORT 9876    
#define DOMAIN_FILE "domain.txt"

void erro(char *s);
char* search_domain(const char *domain);
void convert_number(int num, char *binary, char *hexadecimal );

int main(void) {
    struct sockaddr_in si_minha, si_outra;
    int s, recv_len;
    socklen_t slen = sizeof(si_outra);
    char buf[BUFLEN];
    char response[BUFLEN];

    // Cria um socket para recepção de pacotes UDP
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        erro("Erro na criação do socket");
    }

    // Configuração do socket address
    si_minha.sin_family = AF_INET;
    si_minha.sin_port = htons(PORT);
    si_minha.sin_addr.s_addr = htonl(INADDR_ANY);

    // Associa o socket ao endereço
    if (bind(s, (struct sockaddr*)&si_minha, sizeof(si_minha)) == -1) {
        erro("Erro no bind");
    }

    printf("Servidor UDP aguardando conexões na porta %d...\n", PORT);
    fflush(stdout);

    while (1) {
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&si_outra, &slen)) == -1) {
            erro("Erro no recvfrom");
        }
        buf[recv_len] = '\0';  // termina nula

        printf("Recebi uma mensagem do sistema com o endereço %s e o porto %d\n", inet_ntoa(si_outra.sin_addr), ntohs(si_outra.sin_port));
        printf("Conteúdo da mensagem: %s\n", buf);
        printf("Recebi um número do cliente: %s\n", buf);

        int num = atoi(buf);
        char binary[50], hexadecimal[20];
        
        convert_number(num, binary, hexadecimal);
        
        snprintf(response, BUFLEN, "Numero em binario: %s\nNumero em hexadecimal: %s\n", binary, hexadecimal);

        /* char *ip = search_domain(buf); // find
        snprintf(response, BUFLEN, "%s\n", ip); */

        // Envia resposta ao cliente
        if (sendto(s, response, strlen(response), 0, (struct sockaddr*)&si_outra, slen) == -1) {
            erro("Erro ao enviar resposta");
        } else {
            printf("Enviado para o cliente: %s\n", response);
        }
        fflush(stdout);
    }

    close(s);
    return 0;
}

// Converte número decimal para binário e hexadecimal
void convert_number(int num, char *binary, char *hexadecimal ) {
    for(int i = 7; i >= 0; i--) {
        binary[7 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';

    snprintf(hexadecimal, 20, "0x%X", num);
}

char* search_domain(const char *domain) {
    static char result[BUFLEN];
    FILE *file = fopen(DOMAIN_FILE, "r");

    if (!file) {
        snprintf(result, BUFLEN, "Erro: Não foi possível abrir o arquivo %s\n", DOMAIN_FILE);
        return result;
    }

    char file_domain[256], file_ip[256];
    while (fscanf(file, "%s %s", file_domain, file_ip) != EOF) {
        if (strcmp(domain, file_domain) == 0) {
            snprintf(result, BUFLEN, "O nome de domínio %s tem associado o endereço IP %s", domain, file_ip);
            fclose(file);
            return result;
        }
    }

    fclose(file);
    snprintf(result, BUFLEN, "O nome de domínio %s não tem um endereço IP associado", domain);
    return result;
}

// Exibe mensagem de erro e finaliza o programa
void erro(char *s) {
    perror(s);
    exit(1);
}
