print("--- CONVERSÃO PARA BINÁRIO E HEXADECIMAL ---")
b = list()
r = 0
def binário(n):
    while n > 0:
        r = n % 2
        n = n//2
        b.append(r)
    b.reverse()
    return b
n = int(input("Digite um número para binário: "))
print(binário(n))

# HEXADECIMAL
b = list()
r = 0
def hexa(n):
    while n > 0:
        r = n % 16
        if r == 10:
            r = 'A'
        elif r == 11:
            r = 'B'
        elif r == 12:
            r = 'C'
        elif r == 13:
            r = 'D'
        elif r == 14:
            r == 'E'
        elif r == 15:
            r == 'F'
        n = n//16
        b.append(r)
    b.reverse()
    return b
n = int(input("Digite um número para hexadecimal: "))
print(hexa(n))

