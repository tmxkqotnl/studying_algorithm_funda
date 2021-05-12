#include <stdio.h>

int heap[10] = { 10,1,3,2,9,5,4,6,8,7 };
int num = 10;

int main()
{
	int c, p, temp;

	// 힙은 부모 노드가 자식 노드보다 무조건 큰 값을 가지게 된다. 
	// 동시에 루트 노드는 반드시 데이터 중에서 가장 큰 값을 가진다.
	// 힙 구성 상향식, 자식 노드가 부모 노드를 다음 차례로 가리키게된다.
	// 그래서 상향식이다.

	for (int i = 1; i < num;i++)
	{
		c = i;
		do {
			p = (c - 1) / 2;
			//자식 노드가 더 크다면 바꿔준다.
			if (heap[c] > heap[p])
			{
				temp = heap[c];
				heap[c] = heap[p];
				heap[p] = temp;
			}
			c = p;
		} while (c != 0);
	}
	//힙 생성 확인을 위한 힙 출력
	for (int i = 0;i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	for (int i = num - 1;i >= 0;i--)
	{
		// 루트 노드를 맨 마지막에 차례로 고정시킨다.
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		
		// 다시 힙 생성 과정을 거쳐 가장 큰 값이 루트 노드로 향하게 한다.
		p = 0;
		do {
			c = p * 2 + 1;

			if (c < i - 1 && heap[c] < heap[c + 1])
				c++;
			if (c < i && heap[p] < heap[c])
			{
				temp = heap[c];
				heap[c] = heap[p];
				heap[p] = temp;
			}

			p = c;
		} while (c < i);
	}

	//오름차순 정렬을 확인하기 위한 힙 출력
	for (int i = 0;i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}