def despedaçado(s):
    nova_s = ''    
    for i in range(len(s)):
        nova_s += s[i]
        print(nova_s)
if __name__ == '__main__':    
    s = str(input("Escreva uma frase: "))
    despedaçado(s)