import sys
input = sys.stdin.readline

class Point:
    def __init__(self, x,y):
        self.__x = x
        self.__y = y

    def getX(self):
        return self.__x
    def getY(self):
        return self.__y
        
def getGCD(a,b):
    while b:
        if a>b:
            c = b
            b = a%b
            a = c
        else:
            b%=a
    return a

def getInterceptX(x,y):
    return (x**2+y**2)/x

def getInterceptY(x,y):
    return (x**2+y**2)/y

def getLeftSide(x,y,gcd):
    global n

    border = int(min(getInterceptY(x,y),n))
    ans = (border-y)*gcd//x
    return ans

def getRightSide(x,y,gcd):
    global n

    border = int(min(getInterceptX(x,y),n))
    ans = (border-x)*gcd//y
    return ans

def PrintNumOfRT(c):
    x,y = c.getX(), c.getY()
    gcd = getGCD(x,y)
    
    print(getLeftSide(x,y,gcd),getRightSide(x,y,gcd))

n,x,y = map(int,input().split())
c = Point(x,y)
PrintNumOfRT(c)
