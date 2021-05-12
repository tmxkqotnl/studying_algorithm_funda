import sys
input = sys.stdin.readline

n = int(input())
seq = [0]*101

def printSeq(product,seq,level):
    print('{}='.format(product),end="")
    for i in range(level+1):
        if i == level:
            print(seq[i])
            break
        print('{}*'.format(seq[i]),end='')
    

def factorizaiton(seq,product,level,i,n):
    while True:
        if product*i>n:
            break
        seq[level] = i
        printSeq(product*i,seq,level)
        factorizaiton(seq,product*i,level+1,i,n)
        i+=1

factorizaiton(seq,1,0,2,n)