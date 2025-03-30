s = str(input("Introduza uma frase: "))
n = 0
for p in s:
    n += 1
    if p == ' ':
        n = 0
        continue
    if n == 1:
        print(p)
    