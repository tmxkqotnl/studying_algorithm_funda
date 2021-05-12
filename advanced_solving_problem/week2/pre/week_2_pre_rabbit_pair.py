import sys 
import time
"""
    “A baby rabbit pair grows into adults in one month, then they give birth to a pair of (male and female) rabbits every month”
    we want to find the number of pairs of rabbits
"""
input = sys.stdin.readline
N = int(input())
P = [0 for i in range(N+1)] ## pair of rabbits
P[0],P[1] = 1,1

def fibo(n):
    if P[n]!=0:
        return P[n]
    P[n] = fibo(n-1)+fibo(n-2)
    return P[n]

def timer(m):
    start = time.time()
    for i in range(N):
        print(fibo(i))
    end = time.time()
    print("time elapsed : ", round(end-start,4))

timer(fibo)

