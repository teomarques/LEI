'''def codificar(t):
    for i in range(len(t)):
        t = t.replace(t[i], t[i+2])
        print(t)
if __name__ == '__main__':
    t = str(input("Escreva uma frase: "))
    codificar(t)'''

def codificar(t):
    abc = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    n = 0
    for i in range(len(t)-1):
        n = abc.index(t[i])
        t = t.replace(t[i], abc[n+2])
        print(t)
if __name__ == '__main__':
    t = str(input("Escreva uma frase: "))
    print(codificar(t))