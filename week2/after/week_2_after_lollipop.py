import sys
import time
input = sys.stdin.readline

N = int(input())
P = [-1 for i in range(N+1)]
P[0],P[1] = 0,1
length = [[1,1],[2,5],[3,8],[4,9],[5,10],[6,17],[7,17],[8,20],[9,24],[10,30]]

def candy(n):
    if P[n] != -1:
        return P[n]
    for i in length:
        if n<i[0]:
            break
        P[n] = max(P[n],i[1]+candy(n-i[0]))
    return P[n]

def elapsedTime():
    start = time.time()
    candy(N)
    end = time.time()
    print("ans : ", P[N]," // time elapsed : ", round(end-start,4))
    
elapsedTime()