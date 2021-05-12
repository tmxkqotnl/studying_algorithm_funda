i = [0]*100
s = [0]*100
seq = [0]*100
d = 0

flag = True

def printSeq(d):
    print("[",end='')
    for i in range(d+1):
        print(seq[i],end='')
        if i<d:
            print(",",end='')
    print("]")

i[0] = 2
while True:
    while s[d]+i[d]>6:
        d-=1
        if d<0:
            flag = False
            break
    if not flag:
        break
    
    seq[d] = i[d]
    printSeq(d)
    s[d+1] = i[d]+s[d]
    i[d]+=1
    d+=1
    i[d] = 2
