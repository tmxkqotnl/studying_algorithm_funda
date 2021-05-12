import sys

input = sys.stdin.readline
N = int(input())
num = [int(input()) for _ in range(N)]
Max = max(num)

table = []

def bSearch(a,l,r,t):
    if l>r:
        print(a[r])
        return
    m = (l+r)//2

    if t == a[m]:
        print(a[m-1])
        return

    if t>a[m]:
        return bSearch(a,m+1,r,t)
    if t<a[m]:
        return bSearch(a,l,m-1,t)

def sieve(n):
    global temp
    temp = [0]*(n+1)
    for i in range(2, int(n**0.5)+1):
        if temp[i] == 0:
            temp[i*2::i] = [1]*((n-i)//i)
    return [i for i in range(2,n+1) if temp[i] == 0]

def sieve_ano(n):
    global temp
    temp = [0]*(n+1)
    for i in range(2,int(n**.5)+1):
        if temp[i] == 0:
            for j in range(i+i,n+1,i):
                temp[j] = 1
    return [i for i in range(2,n+1) if temp[i] == 0]

for i in num:
    s = sieve_ano(i)
    bSearch(s,0,len(s)-1,i)

        