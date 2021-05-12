import sys
input = sys.stdin.readline

n = int(input())
seq = [0]*101

def printSeq(product,sumOf,seq,level):
    print('{}='.format(product),end="")
    for i in range(product-sumOf):
        print("1*",end="")

    for i in range(level+1):
        if i == level:
            print('{}='.format(seq[i]),end="")
            break
        print('{}*'.format(seq[i]),end='')
    
    for i in range(product-sumOf):
        print("1+",end="")
    for i in range(level+1):
        if i == level:
            print('{}'.format(seq[i]))
            break
        print('{}+'.format(seq[i]),end='')

    

def factorizaiton(seq,product,sumOf,level,i,n):
    while True:
        if product*i>n:
            break
        seq[level] = i
        if level>=1:
            printSeq(product*i,sumOf+i,seq,level)
        factorizaiton(seq,product*i,sumOf+i,level+1,i,n)
        i+=1

factorizaiton(seq,1,0,0,2,n)