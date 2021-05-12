import sys
import math
import time
input = sys.stdin.readline

N = int(input())
start = time.time()
div = []

for i in range(1,int(math.sqrt(N))):
    if N%i == 0:
        div.append(i)
        temp = N//i
        if temp!=i:
            div.append(temp)
end = time.time()
div.sort()

for i in div:
    print(i,end=" ")
print("\ntime elapsed :", round(end-start,2),"ms")
