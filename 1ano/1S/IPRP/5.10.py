#5.10

import random

def montecarlo(n):
    face_impar = 0
    for i in range(n):
        x = random.uniform(0, 2)
        y = random.uniform(0, 2)
        if x <= 1 and y > 1:
            face_impar += 1
        elif y <= 1 and x > 1:
            face_impar += 1
        elif x > 1 and y > 1 and x > y:
            face_impar += 1
        return face_impar / n
print(montecarlo(8))