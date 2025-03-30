# Indice:

# Aula 1 - Teórica

## Conjunto de Instruções:
- Vamos utilizar o Assembly MIPS
- Segue uma filosofia RISC

| Linguagem de Alto Nível | Assembly MIPS            |
| ----------------------- | ------------------------ |
| A = B+ C                | add $s0, $s1, $s2        |
| D = E - F               | sub $s3, $s4, $s5        |
| A = B + C - D - E       | Dividir em várias etapas |
| T = B + C               | add $t0, $s1, $s2        |
| T = T + D               | add $t0, $t0, $s3        |
| A = T - E               | sub $s0, $t0, $s4        |
| `                       |                          |
## Tabela Dos Registos MIPS
| nome do registo | Número do Registo | Explicação                                                      |
| --------------- | ----------------- | --------------------------------------------------------------- |
| $zero           | 0                 | Registo que contém a constante 0                                |
| $at             | 1                 | Não sei bem                                                     |
| $v0 - $v1       | 2 - 3             | Armazenar valor a devolver da função(return)                    |
| $a0 - $a3       | 4 - 7             | Armazenar argumentos para passar para as funções                |
| $t0 - $t7       | 8 - 15            | Registos Temporários (Váriaveis)                                |
| $s0 - $s7       | 16 - 23           | Desde que se preserve o valor de entrada na saída podem-se usar |
| $t8 - $t9       | 24 - 25           | Registos Temporários                                            |
| $K0 - $k1       | 26 - 27           | OS Kernel                                                       |
| $gp             | 28                | Ponteiro Global                                                 |
| $sp             | 29                | Stack Pointer                                                   |
| $fp             | 30                | Frame Pointer                                                   |
| $ra             | 31                | Return Address                                                  |
## Fazer Comentários:
```arm
#Isto é um comentário
```

## Valores Imediatos:
- Constantes Numéricas -> "imediatos"

- Adição com imediatos: (apenas 1 imediato)
`addi $s0, $s1, 10`
`#f = g + 10`
- Não existe subtração com imediatos porque o imediato pode ser negativo:
`add $s0, $s1, -10`
`f = g - 10`

## Registo Zero

- Utilizado para criar a instrução move
`add $s0, $s1, $zero` -> move $s1, $s2
`f = g`

- Para inicializar uma variável usamos:
`li $s0, 250` ao invés de `addi $s0, $zero, 250

## Load & Store

### Load:

![[Pasted image 20240916230807.png]]
Exemplo:
`lw $t0, 12($s0)`

Basicamente se existir uma tabela com 4 valores: 10, 20, 30, 40 temos de colocar o $s0 a apontar para o inicio da tabela com um offset de 12 vamos aceder ao indice 3 -> `tab[3]`
```arm
.data
	tab word 10, 20, 30, 40

.text
	la $t0, tab
	li $t1, 4
	li $t2, 0 # I
	li $t3, 0 # SOMA
ciclo:
	#Isto está mal mas pronto
	lw $t0, 0($s0)
	add $t3, $t3, $t0
	addi $t2, $t2, 1  
	add $s0, $s0, $t1
	bne $t2m $t1, ciclo
```

# Aula Laboratorial 1:

```assembly
.data

.text
.globl main

main:

```

## SysCall:
![[Pasted image 20240917171830.png]]
- Colocar um dos códigos no registo $v0 e ele olha para o argumento e imprime o que está lá
- Caso seja ler um int, por exemplo, convém mover para o $a0 o valor que está no $v0 depois do input ser dado pelo utilizador
# Aula 2 - Teórica
- Começámos por rever certas coisas da aula passada e acabar o power point(slide 37 - )
![[Aula1-1.pdf]]
- Podemos ter offset negativo, exemplo:(slide 38 +/-)
`lw $t0, -4($a0)`
- No alinhamento de memória, o offset tem de ser multiplo de 4. Isto porque cada espaço são 4 bytes e pode haver um bus error caso isso não aconteça(slide 45)
- Parte .data serve para colocar dados. Essa parte do código não será executada(slide 47)
- Quando estamos a falar do load bytes o offset pode ser qualquer porque nós podemos querer ir buscar um byte a qualquer zona de memória(slide 48)
- O compilador vai fazer o complemento para dois caso usemos valores negativos(por exemplo -1 é 255 isto porque fica 00000001 invertido = 11111110 e somando 1 vai ficar 11111111 = 255)
- Sempre que tivermos uma variável que não quisermos dar um interpretação numérica é utilizar o lbu(load byte unsigned) ao invés do lb(load byte) por exemplo no caso dos chars(slide 49)
- Para se lê um half-word tem se ser multiplo de 2
![[Aula2.pdf]]
`move $s0, $s1 => add $s0, $s1, $zero`
- Vamos começar por falar nas instruções de decisão
- Ver as instruções e propriedades
- Precisamos de controlar condicionalmente o fluxo do nosso programa(+ riqueza, + complexidade)
- Slide 14 - beq (branch equal), bne(branch not equal)
- utilizar o j ao invés do b. Porque o b é uma instrução de salto relativa. E o j vai para um endereço especificado(slide 16)
- ciclo for = ciclo while = slide 19
- Instrução set on less than = slt $r1, $r2, $r3 (verdade(fica 1 no $r1)(fica 0 se for falso) se o $r2 for menor que o $r3)(slide 23)
## Exercicio de Exame:
![[Pasted image 20240923154325.png]]
- Primeiro exercício = ao 1 do slide 27 (não igual igual mas pronto)
- slt $t0, $s3, $s4 # Se o s3 é menor que o s4 salta fora e $t0 fica 1
- slt $t1, $s5, $s4 # Se o s5 é menor que o s4 salta fora e $t0 fica 1
- Como basta 1 instrução estar falsa para saltar fora então é um OR mas como o objetivo é ficar dentro para decrementar então temos de inverter o `$s3 < $s4 || $s5 >= $s4 ==> ($s3 >= $s4) && ($s5 < $s4)`
- Se a label estiver a mandar para fora do ciclo então é inverter se a label estiver a mandar para o inicio do ciclo então é manter(slide 34 opção correta = 6)
- O professor está a mostrar um slide sobre operações bitwise e operações lógicas
## Mascaras:
- Assumindo que $t0 = 0x12345678
- Utilizar andi com 0xFFF para isolar os ultimos 3 bytes, isto porque o 0 é o absorvente logo só ficam os últimos 4. Fazer & lógico
- andi $t0, $t0, 0xFFF (Resultado = 0x0000678)
- Para forçar um determinado número de bits a 1 basta fazer um OR com 0xFFF(últimos 12 bits)
- ori $t0, $t0, 0xFFF (Resultado = 0x12345FFF)
## Operações de Deslocamento:
Syntax:
	OP $destino, $fonte, imediato
### Shift Instructions:
- srl $r1, $r2, 8 (rodar oito bits para a direita) ou seja
- 0001 0010 0011 0100 0101 0110 0111 1000
- 0000 0000 0001 0010 0011 0100 0101 0110 (Resultado) (dividir por 2)
- sll $r1, $r2, 8
- 0001 0010 0011 0100 0101 0110 0111 1000 
- 0011 0100 0101 0110 0111 1000 0000 0000 (Resultado) ( multiplicar por 2)
- Em C a*= 8, compila como -> sll $s0, $s0, 3
# Aula laboratorial 2:
```assembly
.text
li $s0, 0x10010000
li $s1, 0x0000FF00
li $s1, 0x80
li $s2, 0x40
li $s3, 0x60
sw $s4, 16($s0)
```
Cor funciona com RGB:
- 0x00**FF**(R)**FF**(G)**00**(B)

# Aula Teórica 3:
- Começámos por acabar os slides de operadores aritméticas:
## Slides(Operadores Aritméticos):
![[Aula2.pdf]]
### Multiplicação(slides 6-9):
- Para efetuar operações de multiplicação no MIPS - Utilizar registos HI e LO
- mfhi(move from high) $d <- HI(32 bits mais significativos)
- mflo(move from low) $d <- LO(32 bits menos significativos)
- Exemplo do professor:
	MUL <=> mult $s, $t; mflo $d

### Divisão(slides 10-11):
![[Pasted image 20240930143405.png]]
![[Pasted image 20240930143444.png]]
- Quando utilizamos o div temos de ir buscar o resto e o quociente e ao HI e LO, respetivamente.
## Slides(Operações Lógicas):
![[Aula3.pdf]]
- Mascaras
- Shift right(dividir por 2)
- Shift Left(multiplicar por 2)
- Utilizar arithmetic para o caso de não sabermos que numero estamos a tratar (negativo ou positivo) porque a diferença para o logical é que este preserva o bit de sinal
### Funções:
- Convenção:![[Pasted image 20240930145304.png]]
![[Pasted image 20240930150050.png]]
- Para sabermos o endereço para o qual o programa tem de ir a seguir ao j sum podemos substituir as duas linhas:
![[Pasted image 20240930150221.png]]
- Por "jal(jump and link) sum" que vai colocar em $ra o endereço e saltar para a função:
![[Pasted image 20240930150235.png]]
### DataPath(Pergunta de Exame perguntar que etapa é que está presente na instrução e caminhos ativos):
Slides(20-27)
- Etapa 1: FETCH
	- Somar 4 ao program counter para ele apontar para a próxima instrução
- Etapa 2: DECODE
	- Ler o OPCODE e o valor dos registos
- Etapa 3: ALU
	- (Se a instrução for aritmetica, deslocamento, lógica ou de comparação) ou LW
- Etapa 4: MEMORY ACCESS
	- Load and Store é que trocam informação com a memória
- Etapa 5: Register Write
	- Instruções que escrevem o resultado em algum registo(ou seja, loads e stores e branches não escrevem permanecem ativas)
![[Pasted image 20240930152245.png]]
- O store word não estraga o valor de nenhum registo
- O load está ativo em todas as etapas
![[Pasted image 20240930153933.png]]
## Teórica - Prática:
Para acender o display da direita é:
```assembly
.text
	li $t0, 0xFFFF0010(Endereço do display da direita)
	li $t1, 0x4F (Número 3 no display de 7 segmentos)
	sb $t1, 0($t0) (Colocar o número 3 no display)
```
Primeiro Exercicio Lab 3:
```assembly
.text
	li $t0, 0xFFFF0010(Endereço do display da direita)
ciclo2:
	li $t1, 0x01 (segmento de cima no display de 7 segmentos)
	li $t2, 6 (Repetição do ciclo sem o ponto nem o segmento do meio)
ciclo:
	sb $t1, 0($t0) (Colocar o número 3 no display)
	sll $t1, $t1, 1
	addi $t2, $t2, -1
	bne $t2, $zero, ciclo (Temos de diminuir o run speed)
	j ciclo2
```

# Aula Teórica 4:

## Slides(Representação de Instruções no MIPS):
![[Aula4.pdf]]
- Revisão do Datapath e CPU Clocking: (Exercicio que sai em exame)(slide 1-20)
- Importante apanhar hoje é que as instruções vão ser representadas por números binários
- 1 Instrução => 1 Word em memória
- Existem 3 tipos de Introduções:
![[Pasted image 20241007142729.png]]
### Formato R (de Registers):
- Cada campo tem 5 bits porque 2^5 = 32
- O **OPCODE das instruções do tipo R é sempre 0**, logo a instrução é definida unicamente pelo conteúdo de `funct`
- Na tabela:
![[Pasted image 20241007143539.png]]
- Exemplo:
![[Pasted image 20241007144146.png]]
![[Pasted image 20241007144203.png]]

### Formato I (de imediato):
![[Pasted image 20241007144955.png]]
![[Pasted image 20241007145012.png]]
![[Pasted image 20241007145031.png]]
![[Pasted image 20241007145102.png]]
### Exemplo(addi $21, $22, -50):
1º Passo:
	Consultar Tabela para ir buscar o OPCODE
	001000 (0x08)
2º Passo:
	Colocar o valor dos registos (rs = primeiro operando), (rt = registo de destino) e immediato = -50
	rs = 10110 rt = 10101
	(tratar do -50):
	00110010(inverter 50 e somar 1)
	11001101
		  +1
	11001110 e falta preencher os restantes bits com 1, ou seja, a representação em binário fica:
	0010 0010 1101 0101 1111 1111 1100 1110
	0x2    2    D    5    F    F    C    E

### Pergunta do QUIZ:
Instrução que corresponde a 35 em decimal (transformar em binário) vai dar a instrução subu (0x23)
000000 00000 00000 00000 0000 |10| |0011
0        RS    RT    RD     0   2  3 (0x23)
### Pergunta qualquer de um exame passado:
OPCODE = 0
FUNCT = 0x26
rs = 00110
rt = 00010
rd = 00100
000000 | 00110|00010|00100|00000|100110

### Limitações do formato I:
O valor pode ser superior a 16 Bits:
![[Pasted image 20241007151747.png]]
![[Pasted image 20241007151802.png]]
![[Pasted image 20241007151823.png]]
### Pseudo-Instruções(slide 42-45):
- **Registo $at é utilizado para auxiliar na execução das pseudo-instruções
- Uma das limitações é nas instruções cujo valor imediato contenha mais que 16 bits. Se contiver temos de utilizar o registo $at e depois um or para isolar bits e garantir que trabalhamos só com 16 bits em cada instrução
- ![[Pasted image 20241007151949.png]]
- **No exame** pode sair uma pergunta, por exemplo: Quantas instruções é que uma pseudo instrução pode gerar. Ou um pedaço de código e temos de dizer quantas instruções estão naquele pedaço (instruções + instruções geradas pela pseudo instrução)
### Branches e endereçamento relativo:
- O PC está sempre a apontar para a próxima instrução (porque somamos no inicio logo 4 bytes para ir para lá)
- PC = (PC + 4) + (immediate * 4)
![[Pasted image 20241007153904.png]]
- immediate = número de instruções a saltar (saltar o addi, o jump e para o End:) (isto porque está sempre a apontar para a próxima instrução)
- No caso do **cuidado** a instrução é uma pseudo instrução(> 16 bits) logo o addi ao invés de ser só 1 instrução eram 3 instruções.(add ori add)
### Formato J (de jump/branchs):
![[Pasted image 20241007154311.png]]
- 
![[Pasted image 20241007154336.png]]
- Simplificando o hardware:
![[Pasted image 20241007154352.png]]
- Assumindo que os último 2 bits são 0 ficamos com 28 bits
![[Pasted image 20241007154410.png]]
- Se for necessário dar um salto maior é utilizar o jr
### Pergunta:
- Primeira instrução é: MAL (40000 > 32000 (2^16))
- Segunda Instrução é: MAL, depende do salto for muito grande
- Terceira Instrução é: MAL (subtração) mas devia ser subi
![[Pasted image 20241007154437.png]]
### Formatos:
![[Pasted image 20241007155515.png]]
## Aula Teórico-Prática:
### Instrução à ficha prática 4:
- A ideia disto é para manipular variáveis em assembly:
- temos de dar load address à constante não é load word e para usar depois é 
```assembly
.data
var1: .word 32
var2: .word 0
.text
la $t0, var1 # Carregar o endereço da var1
lw $t1, 0($t0) # Colocar em $t1 o valor da variavel 1
```
- Questão da chamada de funções:
- Seguinte cenário
```assembly
.data
op1: .word 32
op2: .word 48
res: .word 0
.text
la $t0, op1 # Carregar o endereço do primeiro operando
lw $a0, 0($t0) # Colocar em $t1 o valor do primeiro operando
# Segundo Operando
la $t0, op2 # Carregar o endereço do primeiro operando
lw $a1, 0($t0) # Colocar em $t1 o valor do primeiro operando

jal soma

la $t0, res
sw $v0, 0($t0) # Colocar a word na variavel

li $v0, 10 # Código para terminal programa
syscall

# res = soma(op1, op2)
# $a0 . 1º Operando e e, $a1 - 2º Operando
# $v0 = Retorno da função
soma:
	add $v0, $a0, $a1
	jr $ra
	 
```

# Aula Teórica 5:
## Slides(Hierarquia da Memória):
![[Aula5.pdf]]
### Acesso à cache(Exemplos dos slides):
Se a tag for diferente do tag field

# Aula Teórica 6:
## Slides(Ponteiros e Tabelas):
![[Aula6.pdf]]
- Ponteiros
- Endereços
- Alocação de memória
- Tabelas e Array(Utilizar variáveis globais(história do radar))
- Basicamente foi tudo uma revisão de C..
### Pergunta de Exame:
![[Pasted image 20241021152532.png]]



### Quiz - Aritmética de Ponteiros:
#### Operações inválidas:
![[Pasted image 20241021151526.png]]
### Quiz - Tabelas
![[Pasted image 20241021152551.png]]
- p1 = tab[2] = 4
- p2 = Endereço do terceiro elemento
- I1:
	Imprime o endereço do primeiro elemento da tabela (0x62FE20)
- I2:
	Imprime 0x62FE20
- I3:
	Imprime 6 `*(p2) = p1 <=> *(p1+1)`
- I4:
	Imprime 5

### Ficha de Exercícios:


# Aula Teórica-Prática 6:
## Lab6:
- Utilizar ssh e ftp
- Está tudo explicado no pdf do lab6
- Ver o que vinha no zip tem lá todas as instruções(Algumas coisas ainda)
### Código alterado:

```c
#include <stdio.h>
int main(){
	int a, b, c;      // Solicitar o primeiro número
	printf("Enter the first number: ");
	scanf("%d", &a);      // Solicitar o segundo número
	printf("Enter the second number: ");
	scanf("%d", &b);      // Somar os dois números
	c = a + b;      // Exibir a soma em formato hexadecimal
	printf("The sum of %d with %d is %d (in decimal) and 0x%x (in hexadecimal)\n", a, b, c, c);
	return 0;
}
```
### Explicação:

#### Complemento de 2:

- Os números negativos são representados usando o **complemento de 2**.
- Para representar um número negativo em complemento de 2:
    1. Escrever o número em binário (se for positivo).
    2. Inverter todos os bits (obtendo o complemento de 1).
    3. Adicionar 1 ao resultado.

# Aula Teórica 7:
## Slides(Zonas de Memória / Funções e Procedimentos):
![[Aula7.pdf]]
### 3 Zonas de memória para o armazenamento de dados:
![[Pasted image 20241028142853.png]]
![[Pasted image 20241028143315.png]]
### A Stack:
![[Pasted image 20241028144351.png]]
- Cada função tem um frame
![[Pasted image 20241028144402.png]]
## Funções e Procedimentos:
### Chamada de Funções (Revisões):
![[Pasted image 20241028150132.png]]
### Como utilizar a pilha em Assembly:
![[Pasted image 20241028151713.png]]
![[Pasted image 20241028151730.png]]
- Não nos esquecermos de somar 8(ou o valor necessário) ao stack pointer para voltar para o sitio certo
- Mexemos na pilha apenas se uma função precisa de ir buscar outra função
![[Pasted image 20241028152024.png]]
### Convenção dos Registos:
![[Pasted image 20241028152722.png]]
![[Pasted image 20241028152738.png]]
- SP tem que manter o valor(no final da chamada do programa tem de ter o mesmo valor que no início)
![[Pasted image 20241028152751.png]]
- Estes são os registos que podem ser alterados. 16 registos são mais que suficientes para os nossos programas simples
![[Pasted image 20241028152835.png]]
### Mini-Teste:(Penúltima semana de aulas na aula prática)
Funções não vão ser recursivas. Funções não vão ter complexidade como a do fibonacci
# Aula Laboratorial 7:
No final deste trabalho deverá que ser capaz de responder à seguinte lista de questões
relacionadas com a utilização de um debugger:
## 1. Como correr um programa no gdb? (run appendTest)

Para executar um programa com o `gdb`, compila o programa com a flag `-g` para incluir informações de debug e, em seguida, usa o comando:

```bash

gdb ./nome_do_programa
```

No `gdb`, podes correr o programa com:

```gdb

`(gdb) run [argumentos]`
```

Por exemplo:

```gdb

(gdb) run appendTest
```


## 2. Como deve ser feita a compilação para ter o máximo de informação sobre o programa ao correr dentro do gdb?

Para obter o máximo de informações, compila o programa com a opção `-g`:

```bash
gcc -g nome_do_programa.c -o nome_do_programa
```

## 3. Como colocar um breakpoint (ponto de paragem) num programa?

No `gdb`, usa o comando `break` seguido do nome da função, do número da linha ou de uma expressão que indique o local onde queres parar o programa.

Exemplos:

```bash
(gdb) break nome_da_funcao 
(gdb) break numero_da_linha
(gdb) break nome_do_arquivo.c:numero_da_linha
```
## 4. Como colocar um breakpoint que só ocorra quando um conjunto de condições for verdadeiro (por exemplo, quando determinadas variáveis têm um valor específico)?

Podes colocar um breakpoint condicional adicionando uma condição ao comando `break`.

Exemplo:

```gdb
(gdb) break nome_da_funcao if variavel == valor
```
Este breakpoint apenas será ativado quando `variavel` for igual a `valor`.

## 5. Como executar a linha seguinte do programa em C depois de um break?

Usa o comando `next` para executar a linha seguinte sem entrar em funções chamadas nessa linha.

```gdb
(gdb) next
```

## 6. Se a linha seguinte for uma chamada a uma função, a função é executada num passo único. Como é que se consegue executar o código dentro da função linha a linha?

Para entrar numa função e executar o código dentro dela linha a linha, usa o comando `step`.

```gdb
(gdb) step
```


## 7. Como continuar a correr o resto do programa depois de um break?

Para continuar a execução do programa após parar num breakpoint, usa o comando `continue`:

```gdb
(gdb) continue
```


## 8. Como ver o valor de uma variável (ou mesmo de uma expressão) no gdb?

Para ver o valor de uma variável ou expressão, usa o comando `print`:

```gdb
(gdb) print nome_da_variavel (gdb) print expressao
```
## 9. Como é que se pode configurar o gdb para escrever sempre o valor de uma determinada variável ao executar o programa passo a passo?

Usa o comando `display` para monitorizar continuamente uma variável a cada passo.

```gdb
(gdb) display nome_da_variavel
```
## 10. Como escrever uma lista com todos os variáveis e respetivos valores no ponto do programa onde nos encontramos?

Para ver o valor de todas as variáveis no escopo atual, usa o comando `info locals`:

```gdb
(gdb) info locals
```
## 11. Como sair do gdb?

Para sair do `gdb`, usa o comando `quit`:
```gdb
(gdb) quit
```

## 2 a)
O erro era a maneira como a string era obtida. Quando passámos o ponteiro como parametro do `gets` estavamos a meter no endereço do ponteiro o input lido o que resultava num segmentation fault

## 3 b)
Quando fiz `frame 2` apareceu o comando `scanf("%d", input)`que está incorreto pois devemos passar o endereço da variável input e não ela mesma
## 4
Basicamente o sum não era retornado logo o seu valor não era mantido. Por isso fica 0/values. Passando o endereço de sum para a função e alterando o parâmetro já fica bem o programa

## 5.
### 1. Função `bin_img()` em `bin_img.c`

A função `bin_img()` deve percorrer todos os píxeis da imagem e aplicar o limiar. Cada pixel abaixo do limiar é definido como 0, e cada pixel igual ou acima do limiar é definido como 255.

```c

#include "bin_img.h"
void bin_img(unsigned char *img, int width, int height, int limiar) {     for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int index = i * width + j;
			img[index] = (img[index] < limiar) ? 0 : 255;
		}
    } 
}
```
### 2. Modificar `main.c` para aceitar o valor de limiar via linha de comando

No `main.c`, precisaremos adicionar um parâmetro para o limiar ao chamar o programa. Vamos incluir a função `atoi()` para converter o argumento do limiar, que é uma string, para um inteiro.

```c

#include <stdio.h>
#include <stdlib.h>
#include "bin_img.h"
int main(int argc, char *argv[]) {
     if (argc < 4) {
	    fprintf(stderr, "Usage: %s <input.pgm> <output.pgm><threshold>\n", argv[0]);
		return 1;
	}      
	int threshold = atoi(argv[3]);
	unsigned char *img;
	int width, height;
	return 0;
}
```

### 3. Criar o Makefile

Para compilar `main.c` e `bin_img.c` e criar o executável `binariza`, podes usar o seguinte **Makefile**:

```makefile

CC = gcc
CFLAGS = -Wall -std=c99
all: binariza
binariza: main.o bin_img.o
 	$(CC) $(CFLAGS) -o binariza main.o bin_img.o
main.o: main.c bin_img.h
 	$(CC) $(CFLAGS) -c main.c
bin_img.o: bin_img.c bin_img.h
 	$(CC) $(CFLAGS) -c bin_img.c  
 clean: 
	 rm -f *.o binariza
```
### 4. Executar o Programa

Depois de compilar com `make`, podes executar o programa da seguinte forma:

```bash
./binariza input.pgm output.pgm 128
```
Aqui, `128` é o valor do limiar que será usado para a binarização da imagem. Se `input.pgm` contiver uma imagem em tons de cinza, `output.pgm` terá a imagem binarizada, onde píxeis abaixo de 128 são convertidos para 0 e os iguais ou acima para 255.

# Aula Teórica 8:

## Slides (Gestão de Memória Dinâmica):
![[Aula8.pdf]]
### Quiz - Prós e Contras dos "Fit":
![[Pasted image 20241104144519.png]]
A - Verdade, pois no inicio podem ficar vários pequenos blocos

B - Falto porque o next-fit vai continuar de onde ficou da última vez, evitando que seja necessário voltar ao inicio cada vez que se quer alocar memória

C - É falso, pois o best-fit vai à procura do bloco que tenha o tamanho certo, fazendo com que fique o menor número de blocos pequenos

## Introdução ao Mips(slides):
![[Aula9.pdf]]
- .globl sym - Se uma função for para ser utilizada noutro ficheiro temos de utilizar o .globl label
- sd = store double - conseguir guardar dois registos
### Perguntas de Exame(2):
![[Pasted image 20241104154906.png]]
![[Pasted image 20241104154917.png]]

- O que é que acontece se referenciar duas vezes o label str(Resposta = 1 para cada referencia)
- Dica: Atenção que se por acaso o valor da constante str couber em 16 bits, só se tem uma entrada não é necessário fazer o desdobramento(ter duas entradas).
### Exercicio 1:
![[Pasted image 20241104155259.png]]
Mas o la são duas instruções porque o endereço é > que 16 bits. Se fosse um endereço tipo 02000 então seria -4
Por causa do la, vai ser -5 instruções, porque o la são 2 instruções. 
Transformar -5, inverter e somar 1 vai dar 0xFFFB
### Exercício 2:
![[Pasted image 20241104155650.png]]
- Loop não entra na tabela de realocação(resolve-se logo na fase de assemblagem)
- array (fica no endereço acima de 16 bits logo é desdobrado logo temos duas entradas)
- func1 func2, array(que são duas)
- Resposta: 4 entradas

# Aula Teórica 9:
![[Aula10.pdf]]
- Começámos por relembrar o Datapath(5 etapas)
- Pipelining, é uma maneira eficiente de aproveitar os recursos do processador isto porque ao avançar numa etapa do datapath os componentes que estiveram envolvidos nessa etapa não vão ser usados até à próxima instrução então com o pipelining sempre que um componente está disponivel ele vai ser usado
![[Pasted image 20241118142903.png]]
![[Pasted image 20241118142915.png]]
## Conceitos importantes:
![[Pasted image 20241118143622.png]]
![[Pasted image 20241118143608.png]]
- O desempenho global é limitado pela duração da etapa mais lenta(Mesmo que haja uma mais rápida ela vai ter de esperar que a outra mais lenta acabe)
- Bubble(stall) que nada mais é do que um periodo de tempo em que um recurso fica à espera de outro para poder retomar a atividade
## Problemas no Pipeline(Otimização):
- Ver slides para Problema / Solução
- Instrução `nop` usada para optimizar
- Instrução a seguir ao branch vai ser sempre executada
- Vamos ter de ser nós a fazer o delayed branch no ultimo lab ig
- Reordenar o código para optimizar ciclos de relógio
- ![[Pasted image 20241118151943.png]]
- Escolher instruções cujo branch não esteja dependente
- .SET NO REORDER
- Código que está aqui no meio não vai ser reordenado pelo compilador
- .SET REORDER
### Forwarding:
(Problema:)
![[Pasted image 20241118152702.png]]
Solução:
![[Pasted image 20241118152626.png]]
## Pergunta de Exame:
4 valores de 20.
Identificar conflitos e temos de apresentar a solução.
### Quiz(exemplo de pergunta de exame):
![[Pasted image 20241118154023.png]]
F D A **M** R +1
  F D **A** M R +2 (instrução + stall)
    F D A **M** R +1
      F D **A** M R +2(Instrução + stall)
        F **D** A M R +1
          F D A M R +1
          8 ciclos de relógio para a execução
- lw está disponivel **depois do M** mas nós precisamos dele **antes do A** logo temos Stall (nop) cicloderelógio +1
- Se é um **store word** **não estraga o valor de t0**, só vai guardar o t0(**não há stall**)
- Precisamos do registo t0 à entrada da memória. Mecanismo de forwarding resolve a situação
- ADDI - O s1 não foi alterado logo não há dependências
- bne - A instrução precisa do $s1 **antes do D**ecoder mas ela só está disponivel na **depois da A**lu
- nop - Instrução normal

![[Pasted image 20241118154051.png]]
- colocar o addi entre o lw e o addu para finalizar a dependencia de uma instrução com a outra. só se tem de alterar o offset para 4
- e ao passar o sw para depois do bne retira-se o nop fazendo com que 2 se transformem em 1 ciclo
![[Pasted image 20241118155744.png]]
- 5 Ciclos de relógio porque já não há nenhum hazard

# Aula Teórica 10:
![[Aula11.pdf]]

- Dispositivos lentos e rápidos partilhavam o mesmo bus então a solução que se encontrou foi criar-se dois buses (1 de alta velocidade e 1 de baixa velocidade)
## Mini-Teste: Próxima Semana
- A duração do LAB 8 +/-
- NÃO VAI TER FUNÇÕES A CHAMAR OUTRAS FUNÇÕES
- SIMPLES
- 40 minutos
- main.c e o main.s
# Aula Teórica 11:
## Resolução Exame de Época Normal 2024 (9 de Janeiro):
![[ExameAC2024Normal.pdf]]
### Pergunta 1:
![[Pasted image 20250107202853.png]]
- A: Verdadeira. Não há vantagem
- B: Falso. Localidade Espacial e Temporal
- C: Falso. À medida que o custo de transferir aumenta o tempo médio de acesso também aumenta
- D: Falso. Bloco não é apagado
### Pergunta 2:
![[Pasted image 20250107202919.png]]
p1 = endereço que aponta para 32 -> \*p1 = 32
p2 = endereço que aponta para 4 -> \*p2 =4
p3 = endereço de p1 = endereço que aponta para o endereço que aponta para 32 -> \*\*p3 = 32
4 + 16 - 4 = 16
- A: Opção certa
- B: X
- C: X
- D: X
### Pergunta 3:
![[Pasted image 20250107202936.png]]
- A: Falso, precisa da ALU
- B: Verdadeira, está ativa em todas as etapas do datapath 
- C: Falso: 
- D: Falso:
### Pergunta 4:
![[Pasted image 20250107202949.png]]
- TamanhoCache = 512KB
- TamanhoBloco = 256 bytes
Tag | IND | OFFSET
16  |  8  |  8
- Quantos Blocos consigo ter na minha Cache
- Nº Blocos = TC / TB = 2^19(2^9 * 2^10) / 2^8 = 2^11 / 2^8(INDEX) = 2^3 = 8 (**8-way set-associative cache**)
### Pergunta 5:
![[Pasted image 20250107203004.png]]
PC está na instrução a seguir ao beq
- andi $16, $0, 0x000FFFFF (+ 16 bits) (0000xxxx para ser menos de 16) logo estão 3 instruções(la $AT, 0x000F,ori $AT, $AT, 0xFFFF)
- andi $17, $17, 1 = 1 instrução
- andi $18, $16, 0x1234 = 1 instrução
- slti $8, $17, 5 = 1 instrução
- mul $12, $11, 100 (instução nativa é mult) = 2 instruções. mult + mflo
- Codificar o valor -9
- 0000 1001
- 1111 0110
- ...... +1
- ----------
- 1111 0111 (F 7) Alinea C
### Pergunta 6:
![[Pasted image 20250107203023.png]]
- A: Falso, jal
- B: Falso, pode-se saltar para posições longe
- C: Falso, -32768 e +32768 
- D: Verdade, mesmo o jump, só há 24 bits para codificar o valor absoluto. Mas com o jr, pode ser até 32 bits
### Pergunta 7:
![[Pasted image 20250107203036.png]]
- Parte Baixa, logo é a A ou B. E para se juntar dois valores usa-se o Ori. **Opção B**

### Pergunta 8:
![[Pasted image 20250107203049.png]]
- Tabela de Alocação: Referenciam endereço absoluto
- O que importa são os labels:
- la $a0, array: não é nativa, 2 intruções = lui $A0, ARRAY.HIGH (16bits+signi), ORI $A0, $A0, ARRAY.LOW (2 entrads)
- la $a0, array: (outras 2 entradas)
- jal func1 = 1 entrada
- jal func2 = 1 entrada
- Total = 6 entradas **Opção D**

### Pergunta 9:
![[Pasted image 20250107203100.png]]
- Tipo de Instrução: 6 bits OPPCODE | 5 bits RS | 5 bits RT | 5bits RD | 5 bits SHIFT AMOUNT | 6 bits FUNCT
  0000 |00 00| 110 0|0101| 0010|0 000|00 10|0100
     0    0     C      5     2    0     2     4
- **OPÇÃO A** 

### Pergunta 10:
![[Pasted image 20250107203109.png]]


### Pergunta 11:
![[Pasted image 20250107203123.png]]
- CPIreal = 5
- Hri=0.9
- MRd= 0.3
- Mp = 10 ciclos
- Rd=0.4
- CPI REAL = CPI IDEAL + MRi * MP + Rd * MRd * MPd
- 5 = CPI IDEAL + 0.1 * 10 + 0.4 * 0.3 * 10
- CPI IDEAL = 5 - 22 = 2.8
### Pergunta 12:
![[Pasted image 20250107203133.png]]
- primeira não faz sentido. Primeiro é compilar
- -c é para gerar o ponto .o que não é necessário
- -O maiusculo é para otimizar
- **OPÇÃO D**

### Pergunta 13:
![[Pasted image 20250107203148.png]]
- shift right para dividir, por 16 é 4 bits
- sra o bit de sinal fica. Logo **OPÇÃO B**

### Pergunta 14:
![[Pasted image 20250107203157.png]]
- AMAT = Tc1 + MRc1 * (TC2 + MRC2 * MPm)
- 16 = 10 + MRc1 * (20 + 0.2 * 200)
- 6 = 60MRc1 <=> MRc1 = 0.1 logo o hit rate é 90% **OPÇÃO A**

### Pergunta 15:
![[Pasted image 20250107203207.png]]
- slt $t0, $s3, $s4 ( $s3 < $s4)
- slt $t1, $s5, $s4 ( $s5 < $s4)
- add $t0, $t0, $t1
- beq $t0, $0, out (ou seja se as condições forem derem 0)
- como é um ciclo while queremos que fique no ciclo
- Instrução para sair do ciclo
- ($s3 >= $s4 ) and ( $s5 >= $s4)
- Negar o original para ficar no ciclo
- ($s3 < $s4 ) or ( $s5 < $s4)
**OPÇÃO D**

### Pergunta 16:
![[Pasted image 20250107203218.png]]
- jr = instrução do tipo R
- é verdade também
- são 5 bits, logo deslocamento máximo é 31
- é 2^15 porque o primeiro bit é sinal logo **OPÇÃO D**
### Pergunta 17:
![[Pasted image 20250107203228.png]]
- A: Variaveis globais: dados estaticos; variaveis locais: pilha; alocação dinamica de memória: heap logo é **VERDADEIRA**.
- B: F
- C: F
- D: F


### Pergunta 18:
![[Pasted image 20250107203238.png]]
- polling são desperdiçados ciclos de relógio a perguntar ao processador se está pronto
- O I/O requer mais instruções logo não simplifica o hardware
- Trivial
- É mais eficiente mas mais difícil. Programação assíncrona

### Pergunta 19:
![[Pasted image 20250107203247.png]]
- $t0 = -12
- $t1 = -48
- $sra Fica com o sinal, logo $t2 = -24
- **OPÇÃO B**


### Pergunta 20:
![[Pasted image 20250107203257.png]]
- mult $a1, $a2
- mflo $s0
- **OPÇÃO A**
### Pergunta 21(pipelining):