import sys
input = sys.stdin.readline

def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def largestPrimeNumber(n):
    i = n
    while i>=int(n**0.5):
        if isPrime(i):
            print(i)
            return
        i-=1
    
n = int(input())
numbers = [int(input()) for _ in range(n)]

for i in numbers:
    largestPrimeNumber(i)




