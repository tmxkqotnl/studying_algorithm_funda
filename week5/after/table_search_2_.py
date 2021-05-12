import sys

input = sys.stdin.readline
n = int(input())
case = [int(input()) for _ in range(n)]
m = max(case)

def primeSeive(n):
    arr = [0]*(n+1)
    for i in range(2,int(n**0.5)+1):
        if arr[i] == 0:
            arr[i*2::i] = [1]*((n-i)//i)
    return [i for i in range(2,n+1) if arr[i] == 0]

def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def rowTop(n,seive):
    row = []
    for i in range(1,len(seive)):
        sumOf = sum(seive[:i])
        row.append(sumOf)
        if sumOf>n:
            break
    
    return row

def binarySearch(l,r,target,arr):
    if l>r:
        return r
    mid = (l+r)//2
    if arr[mid] == target:
        return mid
    if arr[mid]>target:
        return binarySearch(l,mid-1,target,arr)
    else:
        return binarySearch(mid+1,r,target,arr)

seive = primeSeive(m)
top = rowTop(m,seive)

for i in case:
    idx = binarySearch(0,len(top)-1,i,top)
    while not isPrime(top[idx]):
        idx-=1
    print(top[idx],len(top[:idx+1]))


