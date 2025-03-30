import turtle as t

hora = int(input("Horas: "))
minuto = int(input("Minutos: "))

t.penup()
t.goto(0, -150)
t.pendown()
t.circle(150)
t.penup()
t.goto(0, 0)
t.pendown()
t.seth(90)

def horas(hora):
    ang = hora * 30
    t.right(ang)
    t.forward(100)

def minutos(minuto):
    ang = minuto * 6
    t.right(ang)
    t.forward(130)
if hora > 0:
    horas(hora)
    t.penup()
    t.goto(0, 0)
    t.pendown()  
    t.seth(90)
    minutos(minuto)