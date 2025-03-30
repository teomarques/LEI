palavra = str(input("Digite uma palavra: "))
for c in palavra:
    for v in "aeiou":
        if c == v:
            palavra = palavra.replace(c, ' ')
print(palavra)