import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int,input().split()))

def binarySearch(l,r,target):
    if l>r:
        return False
    """
        <target => return to
        >target => return from
    """
    mid = (l+r)//2

    if arr[mid] == target:
        return True

    if arr[mid]<target:
        return binarySearch(mid+1,r,target)
    else:
        return binarySearch(l,mid-1,target)


print(binarySearch(0,9,N))