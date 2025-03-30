#3.7
import math
def entropia(n, m):
    p_1 = n / (n + m)
    p_2 = m = (n + m)
    p = (p_1, p_2)
    soma = 0
    
    for i in range(2):
        soma -= p[i] * math.log2(p[i])
        
        return soma
    
if __name__ == '__main__':
    n = int(input("Dê um primeiro valor: "))
    m = int(input("Dê um segundo valor: "))
    print(entropia(n, m))