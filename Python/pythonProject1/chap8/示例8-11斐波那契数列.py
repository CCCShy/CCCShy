def fac(n):
    if n<=2:
        return 1
    else:
        return fac(n-1)+fac(n-2)

for i in range(1,50):
    print(fac(i))