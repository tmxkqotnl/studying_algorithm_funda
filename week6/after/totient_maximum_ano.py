import sys
input = sys.stdin.readline

def PhiUsingPrimeFactorization(n):
    phi = n
    if n%2 == 0:
        phi *=(2-1)/2
        while n%2 == 0:
            n//=2
    for p in range(3,int(n**0.5)+1,2):
        if n%p == 0:
            phi*=(p-1)/p
            while n%p == 0:
                n//=p
    if n>2:
        phi *=(n-1)/n
    
    return phi

n = int(input())
ans = 1
ans_idx = 0
for i in range(2,n+1):
    val = i/PhiUsingPrimeFactorization(i)
    if ans != max(ans,val):
        ans = val
        ans_idx = i

print(ans, ans_idx)
