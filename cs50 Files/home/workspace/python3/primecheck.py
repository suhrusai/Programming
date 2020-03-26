n=int(input())
def primecheck(n):
    for i in range(2,n):
        if n%i==0:
            return False
    return True

if primecheck(n):
    print("prime")
else:
    print("Not prime")