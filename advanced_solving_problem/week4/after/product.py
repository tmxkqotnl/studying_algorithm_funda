import sys
input = sys.stdin.readline

N,p = list(map(int,input().split()))

""" i = 1
while True:
    j = i**p
    if j>N:
        break
    print(j)
    i+=1 """

for k in range(1,N):
    j = k**p
    if j>N:
        break
    print(j)
