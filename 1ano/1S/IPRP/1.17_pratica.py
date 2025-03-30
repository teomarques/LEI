import math as m

cx = int(input("Coordenada X: "))
cy = int(input("Coordenada Y: "))
alfa = m.atan(cy/cx)
r = m.sqrt(cx**2 + cy**2)
print("cartesianas: ({}, {})\npolares: ({:.0f}, {:.0f})".format(cx, cy, r, alfa))