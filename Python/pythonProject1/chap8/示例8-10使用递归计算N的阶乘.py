def fac(n):
    if n==1:
        return 1
    else:
        s = n * fac(n - 1)
        return s
print(fac(5))