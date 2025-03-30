import turtle as t

t.Screen().bgcolor('blue')
t.seth(-180)
t.penup()
for c in range(0, 200, 5):
    t.stamp()
    t.circle(25 + c, -30)
t.exitonclick()