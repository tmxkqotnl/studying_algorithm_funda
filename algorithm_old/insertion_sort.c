#include <stdio.h>

int main()
{
	const int num = 10;
	int arr[] = { 9,1,2,10,4,3,5,7,6,8 };
	int i, j, temp;

	// �迭�� ���������� Ž���ϸ鼭 ������ ��ġ�� ã���ش�.
	for (i = 0;i < num-1;i++)
	{
		j = i;
		while (j >= 0&&arr[j] > arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}

		//���� ������ �����ֱ����� �迭 ���
		for (int k = 0; k < num;k++)
			printf("%d ", arr[k]);
		printf("\n");
	}

	return 0;
}