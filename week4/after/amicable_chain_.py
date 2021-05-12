import sys
input = sys.stdin.readline

def findSumOfN(s,n):
    for i in range(2,int(n**0.5)+1):
        j = i
        while i*j<=n:
            s[i*j]+=i
            if i!=j:
                s[i*j]+=j
            j+=1
            
def findSum(n):
    s = 1
    for i in range(2,int(n**0.5)+1):
        rest = n%i
        if rest == 0:
            s+=i
            if i!=rest:
                s+=rest
    return s

def amicable_chains(s,n):
    for i in range(2,n):
        arr = [1]
        j = s[i]
        while j not in arr:
            while j>n and j not in arr:
                arr.append(j)
                j = findSum(j)
            arr.append(j)
            j = s[j]
            
        if i in arr:
            print(i, len(arr)-1)
        
n = int(input())
s = [1]*(n+1)
findSumOfN(s,n)
amicable_chains(s,n)