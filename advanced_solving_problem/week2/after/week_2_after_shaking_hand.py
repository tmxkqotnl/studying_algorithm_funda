import sys
import time
input = sys.stdin.readline

N = int(input())
P = [0 for i in range(N+1)]
P[0],P[1] = 1,1

def shaking_hand(n):
    if n == 1 or P[n] != 0:
        return P[n]
    
    for i in range(0,n):
        P[n] += shaking_hand(i)*shaking_hand(n-1-i)

    return P[n]

start = time.time()
shaking_hand(N)
end = time.time()
print("P : ",P, "// P[N] = ",P[N], "// time elapsed : ", round(end-start,2))