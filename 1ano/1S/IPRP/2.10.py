#2.10

import turtle
import random
turtle.speed(0)
l = 10
color = ['red', 'yellow', 'green', 'blue', 'black', 'orange', 'pink']
for i in range(50):
    turtle.penup()
    turtle.goto(-l/2, -l/2)
    turtle.pendown()
    turtle.pencolor(color[random.randint(0, 6)])
    for i in range(4):
        turtle.forward(l)
        turtle.left(90)
    l += 10
turtle.exitonclick()