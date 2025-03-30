#2.3 passeio aleatório

import turtle
import random
turtle.speed(0)
ang = 0
r = 0
g = 0
b = 0
def passeio_aleatório():
    n = 1
    while True:
        d = random.randint(30, 150)
        ang = random.randint(1, 360)
        r = random.randint(0, 255)
        g = random.randint(0, 255)
        b = random.randint(0, 255)
        if n % 5 == 0:
            turtle.goto(0, 0)
        turtle.pencolor("#%02x%02x%02x" % (r, g, b))
        turtle.forward(d)
        turtle.right(ang)
        n += 1
if __name__ == '__main__':
    passeio_aleatório()
    turtle.exitonclick()