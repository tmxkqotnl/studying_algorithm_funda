# elements are >=2 and sum of elements in array is <=6

seq = [0]*100

def printSeq(d):
    print("[",end='')
    for i in range(d+1):
        print(seq[i],end='')
        if i<d:
            print(",",end='')
    print("]")

def findAllSeq(s,d):
    i = 2
    while i+s<=6:
        seq[d] = i
        printSeq(d)
        findAllSeq(s+i,d+1)
        i+=1

findAllSeq(0,0)