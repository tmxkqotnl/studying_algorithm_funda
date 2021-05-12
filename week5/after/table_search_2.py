import sys

input = sys.stdin.readline
N = int(input())
num = [int(input()) for _ in range(N)]
Max = max(num)

table = []
temp = [0]*(Max+1)

def bSearch(a,l,r,t):
    if l>r:
        return r
    m = (l+r)//2

    if t == a[m][0]:
        return m

    if t>a[m][0]:
        return bSearch(a,m+1,r,t)
    if t<a[m][0]:
        return bSearch(a,l,m-1,t)

def sieve():
    for i in range(2, int(Max**0.5)+1):
        if temp[i] == 0:
            temp[i*2::i] = [1]*((Max-i)//i)
    return [i for i in range(2,Max+1) if temp[i] == 0]

def makeTable(arr):
    for i in range(len(arr)):
        table.append([sum(arr[:i+1]), len(arr[:i+1])])

s = sieve()
makeTable(s)

for i in num:
    idx = bSearch(table,0,len(table)-1,i)
    while table[idx][0] not in s:
        idx-=1
    print(table[idx][0],table[idx][1])





        