import sys
import math

input = sys.stdin.readline

N = int(input())
s = [0]*(N+1)

# only even num
for i in range(2,N//2+1,2):
    j = 2
    while i*j<=N:
        s[i*j]+=i
        j+=1

for i in range(2,N+1):
    print("s[%d] = %d"%(i, s[i]))