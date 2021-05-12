import sys
input = sys.stdin.readline

def gcd(a,b):
    print("Greatest common divisor between",a,"and",b,"is",end=" ")
    while b:
        if a>b:
            c = b
            b = a%b
            a = c
        else:
            b%=a
    print(a)

gcd(51,31)

