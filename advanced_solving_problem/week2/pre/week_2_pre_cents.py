import sys
import time
import copy

input = sys.stdin.readline
N = int(input()) ## N>=8
P = [[0] for i in range(N+1)]
P[3] = [3]
P[5] = [5]

def timer(m):
    ans = False
    start = time.time()
    for i in range(8,N+1):
        ans = m(i)
        if ans == False:
            break
        print(P[i], sum(P[i]))

    end = time.time()
    print("time elapsed : ", round(end-start,2))
    print("result : ", str(ans))

def check(n):
    if sum(P[n-5])+5 == n:
        P[n] = copy.deepcopy(P[n-5])
        P[n].append(5)
        return True
    elif sum(P[n-3])+3 == n:
        P[n] = copy.deepcopy(P[n-3])
        P[n].append(3)
        return True
    elif 5 in P[n-1] :
        P[n] = copy.deepcopy(P[n-1])
        P[n].pop(P[n].index(5))
        P[n].append(3)
        P[n].append(3)
        return True
    elif 5 not in P[n-1] == n:
        P[n] = copy.deepcopy(P[n-1])
        for i in range(3):
            P[n].pop(P[n].index(3))
        P[n].append(5)
        P[n].append(5)
        return True

    return False
            
timer(check)
