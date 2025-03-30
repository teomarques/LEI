print("MILHAS%8.sQUILÔMETROS"%' ')
milhas = float(10)
km = float(0)
for i in range(10):
    milhas += 1
    km = milhas * 1.609
    print("{0:<10.2f}".format(milhas) + "{0:>10.2f}".format(km))
