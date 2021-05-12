# number of junctions of circles
import sys
import time
input = sys.stdin.readline

N = int(input())
P = [0 for i in range(N+1)]

def circle(n):
    if P[n] !=0 or n == 1:
        return P[n]

    #circle(n-1)
    P[n] = P[n-1]+2*(n-1)
    return P[n]

def circle_simplify(n):
    return n*(n-1)

start = time.time()
for i in range(1,N+1):
    print(circle(i))
    
for i in range(1,N+1):
    print(circle_simplify(i))
end = time.time()
print("time elapsed : ", round(end-start,4))