import turtle as t

t.speed(0)
def grelha(colunas, linhas, tamanho):
    walk = 0
    sc = t.Screen()
    sc.setup(colunas*tamanho, linhas*tamanho)
    for i in range(colunas):
        t.penup()
        t.goto(-(colunas/2)*tamanho+walk, linhas*tamanho)
        t.pendown()
        t.seth(-90)
        t.forward(linhas*tamanho*2)
        walk += tamanho
    walk = 0
    for i in range(linhas):
        t.penup()
        t.goto(-colunas*tamanho, (linhas/2)*tamanho-walk)
        t.pendown()
        t.seth(0)
        t.forward(colunas*tamanho*2)
        walk += tamanho    
        
if __name__ == '__main__':
    grelha(6, 6, 20)
    t.exitonclick()