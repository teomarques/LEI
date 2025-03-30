def conta_vogais(frase):
    v1 = 0
    v2 = 0
    v3 = 0
    v4 = 0
    v5 = 0
    for c in frase:
        if c == 'a':
            v1 += 1
        elif c == 'e':
            v2 += 1
        elif c == 'i':
            v3 += 1
        elif c == 'o':
            v4 += 1
        elif c == 'u':
            v5 += 1
    t = (v1, v2, v3, v4, v5)
    print(t)
if __name__ == '__main__':
    frase = str(input("sua frase aqui: "))
    conta_vogais(frase)
    