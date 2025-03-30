sum_v3: sum_v3.o soma.o adicional.o novafuncao.o
	gcc -o sum_v3 sum_v3.o soma.o adicional.o novafuncao.o
sum_v3.o: sum_v3.c soma.h adicional.h novafuncao.h
	gcc -c sum_v3.c
soma.o: soma.c
	gcc -c soma.c
adicional.o: adicional.c
	gcc -c adicional.c
novafuncao.o: novafuncao.c
	gcc -c novafuncao.c