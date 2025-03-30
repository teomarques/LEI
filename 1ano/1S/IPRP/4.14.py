n = int(input("Número: "))
r = 0
for i in range(1, 11):
    r = n * i
    print(n, "X%2.d = %2.d" % (n, r))