import sys

input = sys.stdin.readline
n = int(input())
case = [int(input()) for _ in range(n)]

def isPrime(n):
    for i in range(2,int(n**0.5)):
        if n%i == 0:
            return False
    return True

for i in case:
    j = i
    while not isPrime(j):
        j-=1
    print(j)