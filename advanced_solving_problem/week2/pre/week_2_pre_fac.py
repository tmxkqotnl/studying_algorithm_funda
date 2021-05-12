import sys
import time
input = sys.stdin.readline

N = int(input())
P = [0 for i in range(N+1)]
P[0], P[1] = 1,1

def timer(m):
    start_time = time.time()
    for i in range(1,N+1):
        m(i)
    end_time = time.time()
    print("time elapsed",round(end_time-start_time,4))

def factorial(n):
    if n == 0 or n == 1:
        return 1

    return n*factorial(n-1)

def factorial_DP(n):
    if P[n] !=0:
        return P[n]
    
    P[n] = n*factorial_DP(n-1)
    return P[n]

timer(factorial)
timer(factorial_DP)