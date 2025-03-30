li $a0, 10   # Carrega 10 em $a0
li $a1, 6    # Carrega 6 em $a1
li $a2, 7    # Carrega 7 em $a2
li $a3, 10   # Carrega 10 em $a3

sub $v0, $a0, $a2   # Subtrai $a2 de $a0 (10 - 7) e armazena o resultado em $v0
sub $v0, $v0, $a1   # Subtrai $a1 de $v0 (resultado - 6)
add $v0, $v0, $a3   # Soma $a3 com $v0 (resultado + 10)
addi $v0, $v0, 5    # Adiciona 5 ao resultado final
