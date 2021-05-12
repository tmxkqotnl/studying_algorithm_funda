## knapsack problem
import sys
import time
input = sys.stdin.readline

N = int(input())
P = [-1 for i in range(N+1)]
P[0],P[1] = 0,0

items = [[6,30],[4,16],[3,13],[2,9]]

def search(n):
    if P[n] != -1:
        return P[n]
    
    if n>=6:
        P[n] = max(P[n],items[0][1]+search(n-6))
    if n>=4:
        P[n] = max(P[n],items[1][1]+search(n-4))
    if n>=3:
        P[n] = max(P[n],items[2][1]+search(n-3))
    if n>=2:
        P[n] = max(P[n],items[3][1]+search(n-2))

    return P[n]

def elapsedTime():
    start = time.time()
    search(N)
    end = time.time()
    print(P[N])


elapsedTime()