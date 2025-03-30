#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512  // Tamanho do buffer
#define PORT 9876   // Porto para recepção das mensagens

void erro(char *s) 
{
    perror(s);
    exit(1);
}

// função que converte parâmetro inteiro para binário e hexadecimal
void converte_int_bin_hex(char *buf, int recv_len)
{
    int numero = atoi(buf);
    printf("Número: %d\n", numero);
    printf("Número em binário: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (numero >> i) & 1);
    }
    printf("\nNúmero em hexadecimal: %X\n", numero);
}


int main(void) 
{
    struct sockaddr_in si_minha, si_outra;

    int s, recv_len;
    socklen_t slen = sizeof(si_outra);
    char buf[BUFLEN];

    // Cria um socket para recepção de pacotes UDP
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) 
	{
        erro("Erro na criação do socket");
    }

    // Preenchimento da socket address structure
    si_minha.sin_family = AF_INET;
    si_minha.sin_port = htons(PORT);
    si_minha.sin_addr.s_addr = htonl(INADDR_ANY);

    // Associa o socket à informação de endereço
    if (bind(s, (struct sockaddr*)&si_minha, sizeof(si_minha)) == -1) 
	{
        erro("Erro no bind");
    }

    printf("Servidor UDP à escuta no porto %d...\n", PORT);

    // Loop infinito para receber múltiplas mensagens
    while (1) 
	{
        // Espera recepção de mensagem (bloqueante)
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_outra, &slen)) == -1) 
		{
            erro("Erro no recvfrom");
        }

        // Termina a string recebida
        buf[recv_len] = '\0';

        printf("Recebi uma mensagem de %s:%d\n", inet_ntoa(si_outra.sin_addr), ntohs(si_outra.sin_port));
        converte_int_bin_hex(buf, recv_len);
    }

    // Fecha socket (nunca chega aqui devido ao loop infinito)
    close(s);
    return 0;
}