#include <stdio.h>
#define MAX 9999

int main()
{
	int i, j,k = 0, temp, min;
	const int num = 10;
	int arr[] = { 10,1,9,2,4,3,6,5,7,8 };

	// ��������
	// ���� ���� ���Ҹ� ������ ������.
	for (i = 0; i < num;i++)
	{
		//���� ���� ���Ҹ� ã�� ���� min
		min = MAX;
		for (j = i;j < num;j++)
		{
			if (min > arr[j])
			{
				//������ �ε����� ����ϰ� min�� �ʱ�ȭ�Ѵ�.
				k = j;
				min = arr[j];
			}
		}
		// ���� ���� ���� ã�����Ƿ� i�� ��ġ�� �����Ѵ�.
		temp = arr[k];
		arr[k] = arr[i];
		arr[i] = temp;
	}
	
	// ���� Ȯ���� ���� �迭 ���
	for (int p = 0;p < num;p++)
		printf("%d ", arr[p]);
	printf("\n");

	return 0;
}