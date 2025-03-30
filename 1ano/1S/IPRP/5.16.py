# 5.16

s = 0
n = int(input("Introduza um número: "))
for c in range(n-1, 0, -1):
    if n % c == 0:
        s += c
if s == n:
    print("O número é perfeito")
else:
    print("O número não é perfeito")