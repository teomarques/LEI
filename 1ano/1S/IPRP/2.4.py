#2.4

import turtle
import random
turtle.speed(0)
def poligono_regular():
    while True:        
        turtle.goto(0, -380)
        radius = random.randint(5, 380)
        n = random.randint(1, 8)
        turtle.circle(radius, extent=None, steps=n)
if __name__ == '__main__':
    poligono_regular()