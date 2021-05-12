#include <stdio.h>

int heap[10] = { 10,1,3,2,9,5,4,6,8,7 };
int num = 10;

//����� �� ����
void heapfy(int p)
{
	int c = p * 2 + 1;

	//�ڽĳ���� ū ���� ����Ű�� �Ѵ�.
	if (c < num - 1 && heap[c] < heap[c + 1])
		c++;
	//�ڽĳ�尡 �θ��庸�� ũ�ٸ� �ٲ��ش�.
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

	//���ݸ� �ص� �ȴ�. 
	//���� ��������Ʈ���̹Ƿ�
	//�θ��尡 ���ݱ����� ���� �ڽĳ�� ���θ� �˻��ϰԵȴ�.
	for (int i = num/2;i >=0 / 2;i--)
		heapfy(i);

	//�� ������ Ȯ���ϱ� ���� �� ���
	for (int i = 0; i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	//�ݺ��� �� ������ �������� ����
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

	//�������� Ȯ���� ���� �����
	for (int i = 0; i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}