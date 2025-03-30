.data
alfa: .asciiz "abcdefghijklmnopqrstuvwxyz"   # Tabela de caracteres

.text
.globl codifica_string

# Função codifica_string
# Parâmetro: $a0 (endereço da string de entrada)
codifica_string:
    la $t0, alfa           # Carrega a tabela alfabética no $t0

iteraString:
    lb $t1, 0($a0)         # Carrega o próximo caractere da string
    beq $t1, $zero, end    # Se caractere nulo, termina a função
    beq $t1, 32, nextChar  # Ignorar espaços (' ')

    # Reinicia o ponteiro da tabela para cada caractere
    la $t0, alfa

compara:
    lb $t2, 0($t0)         # Carrega caractere atual da tabela
    beq $t1, $t2, troca    # Se caractere coincide, vá para troca
    addi $t0, $t0, 1       # Avança na tabela
    bnez $t2, compara      # Continua a busca se não chegou ao final da tabela
    j nextChar             # Ignorar caracteres fora da tabela

troca:
    lb $t3, 2($t0)         # Carrega caractere 2 posições à frente
    beqz $t3, wrap         # Se ultrapassou 'z', volte ao início da tabela
    sb $t3, 0($a0)         # Substitui caractere na string original
    j nextChar

wrap:
    la $t0, alfa           # Reinicia tabela
    sb $t3, 0($a0)         # Substitui caractere na string original

nextChar:
    addi $a0, $a0, 1       # Avança para o próximo caractere da string
    j iteraString

end:
    jr $ra                 # Retorna ao chamador

