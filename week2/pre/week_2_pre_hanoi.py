import sys
import time

input = sys.stdin.readline
N = int(input())

## from, by, to, number of plates
def hanoi(f, b, t, n):
    if n == 1:
        print(f, " -> ",t)
    else:
        hanoi(f,t,b,n-1)
        print(f," -> ",t)
        hanoi(b,f,t,n-1)

hanoi("A","B","C",N)