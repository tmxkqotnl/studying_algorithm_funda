import sys

input = sys.stdin.readline
N = int(input())
num = [int(input()) for _ in range(N)]
Max = max(num)
table = []
sub_table = []
s = 0

def bSearch(a,l,r,t):
    if l>r:
        return r
    mid = (l+r)//2

    if t == a[mid][0]:
        return mid

    if t>a[mid][0]:
        return bSearch(a,mid+1,r,t)
    if t<a[mid][0]:
        return bSearch(a,l,mid-1,t)

def sieve(n):
    temp = [0]*(n+1)
    for i in range(2, int(n**0.5)+1):
        if temp[i] == 0:
            temp[i*2::i] = [1]*((n-i)//i)
    return [i for i in range(2,n+1) if temp[i] == 0]

def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def makeFirstTable():
    global table
    
    for j in range(len(s)):
        sumOf = sum[s[:j+1]]
        table.append([sumOf,j+1])
        if sumOf>Max:
            break

def makeTable(i):
    global table
    global sub_table
    global s
    
    nextTable = [[0,0] for _ in range(len(table))]

    sub = sum(s[:i])
    idx = i
    while idx<len(table):
        nextTable[idx][0] = table[idx][0]-sub
        nextTable[idx][1] = table[idx][1]-i
        idx+=1
    
    sub_table.append(nextTable)


def tableSearch():
    for i in num:
        left, right = 0,0 # left and right border
        ans = [0,0]
        right = bSearch(table,0,len(table)-1,i)

        while not isPrime(table[right][0]):
            right-=1
        ans[0],ans[1] = table[right][0], table[right][1]
        left = right+2
        # search next table
        for j in sub_table:
            right = bSearch(j,0,len(j)-1,i)
            if left>right:
                break

            while not isPrime(j[right][0]):
                right-=1

            if left<=right and j[right][1]>ans[1]:
                ans[0],ans[1] = j[right][0], j[right][1]
                left = right+2

        print(ans[0],ans[1])

s = sieve(Max)
makeFirstTable()
for i in range(1,len(table)):
    makeTable(i)

tableSearch()


    
