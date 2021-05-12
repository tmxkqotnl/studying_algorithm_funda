import sys
input = sys.stdin.readline

def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def primeProuct(m):
    mul = 1
    arr = []
    i = 2

    while mul*i<=m:
        if isPrime(i):
            mul*=i
            arr.append(mul)
        i+=1

    return arr
def sortingNumbers(arr,pd):
    for i in arr:
        for j in range(len(pd)):
            if pd[-j-1]<=i:
                print(pd[-j-1])
                break
        
n = int(input())
numbers = [int(input()) for _ in range(n)]
m = max(numbers)

pd = primeProuct(m)
sortingNumbers(numbers,pd)





