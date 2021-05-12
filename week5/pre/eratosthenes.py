import sys
import math
input = sys.stdin.readline

N = int(input())
arr = [0]*(N+1)
arr[0],arr[1] = 1,1

def sieve():
    for i in range(2,math.floor(math.sqrt(N))+1):
        if arr[i] == 0:
            for j in range(i+i,N+1,i):
                arr[j] = 1

sieve()
for idx,val in enumerate(arr):
    if val == 0:
        print(idx, end = " ")
print()