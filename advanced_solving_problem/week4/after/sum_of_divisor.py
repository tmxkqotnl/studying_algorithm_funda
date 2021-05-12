import sys
input = sys.stdin.readline

n = int(input())
s = [1]*(n+1)
s[0],s[1] = 0,0

# product tree
for i in range(2,int(n**0.5)+1):
    for j in range(i,n):
        if i*j>n:
            break
        s[i*j] +=i
        if i!=j:
            s[i*j] +=j
            
for i in range(2,n+1):
    print('s[{}]={}'.format(i,s[i]))