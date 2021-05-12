import sys 
import time
input = sys.stdin.readline

s = int(input())
P = [0 for i in range(s+1)]
P[0], P[1] = 1, 3 

def timer(m):
    start_time = time.time()
    for i in range(s):
        m(i)
    end_time = time.time()
    print("time elapsed : ", round(end_time-start_time,4))

def modulo_7(S):
    n = 1
    for i in range(S):
        n*=3
        
    return n%7

def modulo_7_DP(S):
    if P[S]!=0:
         return P[S]

    P[S] = 3*modulo_7_DP(S-1)%7
    return P[S]

timer(modulo_7)
timer(modulo_7_DP)
