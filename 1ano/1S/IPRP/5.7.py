p1 = str(input("Digite uma palavra: "))
p2 = str(input("Digite outra palavra de igual comprimento: "))
if len(p1) != len(p2):
    exit()
porc = len(p1) * 0.1
print("O critério de diferença em 10% das palavras é de {:.2f}".format(porc))
l = list()
c = 0
abc = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
for i in p1:
    pos1 = p1.index(i)
    for j in p2:
        pos2 = p2.index(j)
        if i != j and pos1 == pos2:
            c = abs(abc.index(i)-abc.index(j))
            print("O caractere {} e {} difere em posição em {} e {}, {} posições.".format(i, j, p1, p2, c))
            if c < porc:
                l.append(1)
            else:
                l.append(0)
        else:
            continue
for k in l:
    if k == 0:
        print("as palavras não são amigas.")
        exit()
print("as palavras são amigas")