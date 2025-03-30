texto = str(input("O seu texto aqui: "))
texto = tuple(texto)
c = 0
n = 0
word = ''
for p in texto:
    if p != ' ':
        word += p
    else:
        print(word)
        for l in word:
            n += 1
            if c == 0:
                lant = l
                c += 1
            else:
                if l == lant:
                    c += 1
                    print(c)
            if n == len(word):
                n = 0
                c = 0
            word = ''