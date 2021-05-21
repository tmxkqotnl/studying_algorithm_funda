import sys
import copy
input = sys.stdin.readline

# 주사위 하나
# k 개의 칸
# n 개의 면
# iter 번의 반복

k,n,iter = map(int, input().split())

pre = [0]*(k+1)
after = [0]*(k+1)
pre[1] = 1

# iter만큼 주사위를 던진다
for i in range(iter):
  # 이전 상태를 확인한다. 
  for j in range(1,k+1):
    if pre[j]>0: 
      # 갈 수 있는 state를 찾는다.
      stateY = []
      if j+n>k:
        for t in range(j+1,k+1):
          stateY.append(t)
        for t in range(1,j+n-k+1):
          stateY.append(t)        
      else:
        stateY = [t for t in range(j+1,j+n+1)]
      # 갈 수 있는 state에 대한 확률을 계산한다.
      for q in stateY:
        after[q] += (1/n*pre[j])
  # 상태정보를 갱신한다.   
  pre = copy.deepcopy(after)
  after = [0]*(k+1)    

# 결과 출력
for i in range(1,k+1):
    print('%.5f'%pre[i])