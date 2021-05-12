#include <stdio.h>

// �� ����
// �迭�� ���Ұ� ���� ���ؿ� ���� ��ġ�ؾ��� ���� �����Ų��.
// ��������
void QuickSort(int arr[], int left, int right)
{
	int i, j, pivot, temp;

	//���Ұ� 1���̰ų� �ε����� ������ ����� Ż���Ѵ�.
	if (left >= right)
		return;

	i = left + 1;
	j = right;
	pivot = left;

	while (i <= j)
	{
		// ó������ pivot �� ���� ū ���� ã�´�.
		while (i <= right && arr[i] < arr[pivot]) i++;
		// ���������� pivot �� ���� ���� ���� ã�´�.
		while (j > left && arr[j] > arr[pivot]) j--;

		//���� �������� �ʾҴٸ� Ž�����̴� ���� ���� �ٲ��ش�.
		if (i < j)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	//�� �ε����� ���������Ƿ� pivot ���� �˸��� ��ġ(j)�� �����Ų��.
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;

	// ������ ���ҵ� pivot�� �������� ������ �����Ѵ�.
	QuickSort(arr, left, j - 1);
	QuickSort(arr, j + 1, right);
}

int main()
{
	const int num = 10;
	int arr[] = { 10,1,3,9,2,4,6,5,7,8 };

	QuickSort(arr, 0, num - 1);

	//������ Ȯ���� ���� �迭 ���
	for (int i = 0; i < num;i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}