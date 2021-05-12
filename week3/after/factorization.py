import sys
input = sys.stdin.readline
N = int(input())

i = [2]*100
p = [1]*100
seq = [1]*101
d = 0

flag = True

def printSeq():
    print(str(p[d+1])+"=",end='')
    for j in range(d+1):
        if seq[j]!=1:
            print(seq[j],end='')
            if j<d:
                print("*",end='')
    print()

while True:
    while p[d]*i[d]>N:
        d-=1
        if d<0:
            flag = False
            break
    if not flag:
        break

    if seq[d-1]<=i[d]:
        seq[d] = i[d]
        p[d+1] = i[d]*p[d]
        printSeq()
        i[d]+=1
        d+=1
        i[d] = 2
    else:
        i[d]+=1