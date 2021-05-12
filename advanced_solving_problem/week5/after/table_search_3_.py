#이 코드는 시간초과로 테스트에서 통과하지 못함

import sys

input = sys.stdin.readline
n = int(input())
numbers = [int(input()) for _ in range(n)]
m = max(numbers)

def bSearch(arr,left,right,target):
    if left>right:
        return right
    mid = (left+right)//2
    if target == arr[mid]:
        return mid
    if target>arr[mid]:
        return bSearch(arr,mid+1,right,target)
    if target<arr[mid]:
        return bSearch(arr,left,mid-1,target)


def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def make_table(n):
    temp = [0]*(n+1)
    for i in range(2, int(n**0.5)+1):
        if temp[i] == 0:
            temp[i*2::i] = [1]*((n-i)//i)
    seive = [i for i in range(2,n+1) if temp[i] == 0]

    table = [[0]*len(seive) for _ in range(len(seive))]
    table[0][0] = 2

    for i in range(1,len(seive)):
        table[0][i] = table[0][i-1]+seive[i]

    for i in range(1,len(table[0])):
        for j in range(i,len(table[0])):
            table[i][j] = table[0][j]-table[0][i-1]

    return table

table = make_table(m)


for i in numbers:
    left,right = 0, bSearch(table[0],0,len(table[0])-1,i)
    max_len, max_val = 0,0

    j,k = 0,0
    while left<right:
        k = right
        while k>=left:
            if isPrime(table[j][k]):
                max_len = k-j+1
                max_val = table[j][k]
                left = k+1
                break
            k-=1

        if table[j+1][right+1]<= i:
            right+=1
        left+=1
        j+=1
    print(max_val,max_len)