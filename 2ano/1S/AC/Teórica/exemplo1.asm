.data

loop:
slt	$t0, $s3, $s4
bne	$t0, $0, out
slt	$t1, $s5, $s4
beq	$t1, $0, out	# como a condição de saída é para resultados 0 ou 1,então o operador lógico é OU
addi	$s4, $s4, -1
j 	loop

out:

# como a condição de saída é um OU, a condição de permanência no ciclo, dentro do while, é a inversa (&&) 
# EQUIVALENTE À EXPRESSÃO LÓGICA:
# while(($s3 >= $s4) && ($s5 <$ s4)) {$s4--;}