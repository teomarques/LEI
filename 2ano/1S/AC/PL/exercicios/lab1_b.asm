.data

.text

addi $s0, $zero, 0xFFFF0012	#ENDEREÇO DO KEYBOARD
addi $s1, $zero, 0xFFFF0014	#ENDEREÇO QUE RECEBE LINHA E COLUNA DA TECLA PREMIDA

loop:
li $t1, 1
sb $t1, 0($s0)			#STORE LINHAS
addi $t3, $t3, 1		#CONTADOR
lbu $t2, 0($s1)			#LOAD BYTE UNSIGNED, MANDA O VALOR DA LINHA NO BIT 2 E COLUNA NO BIT 1 PATA T2
sll $t1, $t1, 			#ANDA DE LINHA EM LINHA, SERVE PARA VERIFICAR QUAL FOI A LINHA PREMIDA
bne $t3, 4, loop
addi $t3, $t3, -4
j	loop
