import sys

input = sys.stdin.readline
N = int(input())
num = [int(input()) for _ in range(N)]
Max = max(num)

table = []
temp = [0]*(Max+1)

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

def sieve():
    for i in range(2, int(Max**0.5)+1):
        if temp[i] == 0:
            temp[i*2::i] = [1]*((Max-i)//i)
    return [i for i in range(2,Max+1) if temp[i] == 0]


s = sieve()
for i in num:
    bSearch(s,0,len(s)-1,i)

        