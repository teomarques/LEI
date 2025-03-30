g1 = 0
g2 = 0
g3 = 0
g4 = 0
aguaL = int(input("Indique a quantidade de água: "))
aguamL = aguaL * 1000
if aguamL >= 5000:
    g1 += (aguamL // 5000)
    aguamL -= (g1 * 5000)
if aguamL >= 1500:
    g2 += (aguamL // 1500)
    aguamL -= (g2 * 1500)
if aguamL >= 500:
    g3 += (aguamL // 500)
    aguamL -= (g3 * 500)
if aguamL >= 250:
    g4 += (aguamL // 250)
    aguamL -= (g4 * 500)
if aguamL == 0:
    print("os {}L de água são armazenados em:\n {} garrafas de 5L,\n {} garrafas de 1.5L,\n {} garrafas de 500mL e \n {} garrafas de 250mL.".format(aguaL, g1, g2, g3, g4))
else:
    print("os {}L de água são armazenados em:\n {} garrafas de 5L,\n {} garrafas de 1.5L,\n {} garrafas de 500mL \n e {} garrafas de 250mL, sendo que uma delas contém {}mL de água.".format(aguaL, g1, g2, g3, g4+1, aguamL))