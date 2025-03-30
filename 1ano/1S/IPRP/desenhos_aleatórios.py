import turtle
import random
turtle.speed(0)

def desenhos_aleatorios():
    
    n = 0
    v = 0
    lx = 0
    ly = 0
    distance = 0
    distance2 = 0
    distanceang = 0
    ang = 0
    randang = 0
    girth = 0 
    step = 0
    radius = 0
    radius2 = 0
    
    # CABEÇA
    
    distance = random.randint(80, 120)
    radius = random.randint(80, 120)
    step = random.randint(3, 8)
    turtle.penup()
    turtle.goto(0, 2*radius)
    turtle.pendown()
    turtle.right(180)
    turtle.circle(radius, extent=None, steps=step)
    
    # OLHOS
    
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)    
    turtle.penup()
    turtle.goto(radius/4, radius)
    turtle.pendown()
    turtle.right(180)
    radius2 = random.randint(5, 20)
    turtle.fillcolor("#%02x%02x%02x" % (r, g, b))
    turtle.begin_fill()
    turtle.circle(radius2)
    turtle.end_fill()
    
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)    
    turtle.penup()
    turtle.goto(-radius2-radius/4, radius)
    turtle.pendown()
    turtle.left(0)
    radius2 = random.randint(5, 20)
    turtle.fillcolor("#%02x%02x%02x" % (r, g, b))
    turtle.begin_fill()
    turtle.circle(radius2)
    turtle.end_fill()
    
    # PESCOÇO
    
    girth = random.randint(1, 10)
    distance = random.randint(10, 120)
    turtle.penup()
    turtle.goto(-10 - girth, girth)
    turtle.pendown()
    turtle.setheading(-90)
    turtle.forward(distance)
    turtle.penup()
    turtle.goto(10 + girth, girth)
    turtle.pendown()
    turtle.setheading(-90)
    turtle.forward(distance)
    
    # TRONCO
    
    turtle.penup()
    turtle.goto(0, -distance+10)
    turtle.pendown()
    radius = random.randint(120, 200)
    step = random.randint(5, 15)
    turtle.right(90)
    turtle.circle(radius, extent = None, steps=step)
    
    # BRAÇO ESQUERDO
    
    turtle.penup()
    turtle.goto(-radius+10, (-radius/2)-distance)
    turtle.pendown()
    distance2 = random.randint(50, 200)
    turtle.forward(distance2)
    
    girth = random.randint(15, 30)
    turtle.penup()
    turtle.goto(-radius+10, (-radius/2)-distance-girth)
    turtle.pendown()
    turtle.forward(distance2)
    
    # MÃO ESQUERDA
    
    radius2 = random.randint(25, 75)
    turtle.penup()
    turtle.goto(-radius+10-distance2-radius2, (-radius/2)-distance+radius2-girth/2)
    turtle.pendown()
    turtle.circle(radius2)
    
    # BRAÇO DIREITO
    
    turtle.penup()
    turtle.goto(radius-10, (-radius/2)-distance)
    turtle.pendown()
    distance2 = random.randint(50, 200)
    turtle.right(180)
    turtle.forward(distance2)
    
    girth = random.randint(15, 30)
    turtle.penup()
    turtle.goto(radius-10, (-radius/2)-distance-girth)
    turtle.pendown()
    turtle.forward(distance2)
    
    # MÃO DIREITA
    
    radius2 = random.randint(25, 75)
    turtle.penup()
    turtle.goto(radius-10+distance2+radius2, (-radius/2)-distance-radius2-girth/2)
    turtle.pendown()
    turtle.circle(radius2)
    
    
    
if __name__ == '__main__':
    turtle.onscreenclick(desenhos_aleatorios())
    print("Clique para ver novamente!")