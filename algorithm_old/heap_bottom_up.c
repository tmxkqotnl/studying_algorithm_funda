#include <stdio.h>

int heap[10] = { 10,1,3,2,9,5,4,6,8,7 };
int num = 10;

int main()
{
	int c, p, temp;

	// ���� �θ� ��尡 �ڽ� ��庸�� ������ ū ���� ������ �ȴ�. 
	// ���ÿ� ��Ʈ ���� �ݵ�� ������ �߿��� ���� ū ���� ������.
	// �� ���� �����, �ڽ� ��尡 �θ� ��带 ���� ���ʷ� ����Ű�Եȴ�.
	// �׷��� ������̴�.

	for (int i = 1; i < num;i++)
	{
		c = i;
		do {
			p = (c - 1) / 2;
			//�ڽ� ��尡 �� ũ�ٸ� �ٲ��ش�.
			if (heap[c] > heap[p])
			{
				temp = heap[c];
				heap[c] = heap[p];
				heap[p] = temp;
			}
			c = p;
		} while (c != 0);
	}
	//�� ���� Ȯ���� ���� �� ���
	for (int i = 0;i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	for (int i = num - 1;i >= 0;i--)
	{
		// ��Ʈ ��带 �� �������� ���ʷ� ������Ų��.
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		
		// �ٽ� �� ���� ������ ���� ���� ū ���� ��Ʈ ���� ���ϰ� �Ѵ�.
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

	//�������� ������ Ȯ���ϱ� ���� �� ���
	for (int i = 0;i < num;i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}