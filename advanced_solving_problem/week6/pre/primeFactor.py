import sys
input = sys.stdin.readline

# factorization with prime numbers
def primeFactors(n):
    while n%2 == 0:
        n//=2
        print(2,end=" ")
    
    for i in range(3,int(n**0.5)+1):
        while n%i == 0:
            n//=i
            print(i, end=" ")
    if n>2:
        print(n)

primeFactors(132)
