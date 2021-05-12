#include <stdio.h>

int heap[10] = { 10,1,3,2,9,5,4,6,8,7 };
int num = 10;

//하향식 힙 구성
void heapfy(int p)
{
	int c = p * 2 + 1;

	//자식노드중 큰 값을 가리키게 한다.
	if (c < num - 1 && heap[c] < heap[c + 1])
		c++;
	//자식노드가 부모노드보다 크다면 바꿔준다.
	if (c < num && heap[p] < heap[c])
	{
		int temp = heap[p];
		heap[p] = heap[c];
		heap[c] = temp;
	}

	if (c <= num / 2)
		heapfy(c);
}

int main()
{
	int c, p;

	//절반만 해도 된다. 
	//힙은 완전이진트리이므로
	//부모노드가 절반까지만 가도 자식노드 전부를 검사하게된다.
	for (int i = num/2;i >=0 / 2;i--)
		heapfy(i);

	//힙 생성을 확인하기 위한 힙 출력
	for (int i = 0; i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	//반복적 힙 구성과 오름차순 구성
	for (int i = num - 1;i >= 0;i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		p = 0;
		do
		{
			c = p * 2 + 1;

			if (c < i - 1 && heap[c] < heap[c + 1])
				c++;

			if (c < i && heap[p] < heap[c])
			{
				temp = heap[p];
				heap[p] = heap[c];
				heap[c] = temp;
			}
			p = c;
		} while (c < i);
	}

	//내림차순 확인을 위한 힙출력
	for (int i = 0; i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}