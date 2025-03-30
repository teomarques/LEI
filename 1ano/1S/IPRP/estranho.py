import math as m
n = int(input("n. lados: "))
r = int(input("Raio: "))
area_circulo = (n*(r)**2)*m.cos(m.pi/n)*m.sin(m.pi/n)
ang = 360/n
apotema = (m.cos(ang)*r)
lado = (m.sin(ang)*r)*2
semip = lado*n/2
area_poli = semip*apotema
if area_poli > (90/100)*area_circulo:
    print("o poligono de {} lados é estranho".format(n))
else:
    print("não é")