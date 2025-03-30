import turtle as t
t.speed(0)

t.penup()
t.goto(-100, -100)
t.pendown()
t.color('yellow')
t.begin_fill()
for i in range(4):
    t.forward(200)
    t.left(90)
t.end_fill()
t.penup()
t.goto(50, 0)
t.pendown()

t.seth(90)
t.color('black')
for i in range(6):
    if i == 0:
        t.begin_fill()
    t.circle(50, 60)
    if i % 2 == 0:
        t.end_fill()
        t.penup() 
    else:
        t.pendown()
        t.begin_fill() 
t.fillcolor('black')
t.penup()
t.goto(0, 0)
t.pendown()
t.seth(60)
for i in range(6):
    t.begin_fill()
    t.forward(50)
    t.right(120)
    t.forward(50)
    t.right(120)
    t.forward(50)
    if i % 2 == 0:
        t.end_fill()
        t.penup()
    else:
        t.pendown()
        t.begin_fill()
t.penup()
t.seth(90)
t.goto(15, 0)
t.pendown()
t.begin_fill()
t.pencolor('yellow')
t.circle(15)
t.end_fill()