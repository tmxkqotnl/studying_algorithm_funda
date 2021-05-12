#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//divide and conquer

//���ҽ�Ų �迭�� �����ϴ� �Լ�
int MergeTwoArea(int arr[], int left, int mid, int right)
{
	int i, j, k;
	//�������� �迭�� �ӽ÷� ������ �迭
	int* sort = (int*)malloc(sizeof(int) * (right+1));
	memset(sort, 0, sizeof(int) * (right + 1));

	i = left;
	j = mid + 1;
	k = left;

	//���� ������ ���ʴ�� �����Ѵ�.
	while (i <=mid&&j<=right)
	{
		if (arr[i] < arr[j])sort[k++] = arr[i++];
		if (arr[j] < arr[i])sort[k++] = arr[j++];
	}

	//���� �������� ���� ���Ұ� �ִٸ� ���� �����Ѵ�.
	if (i > mid)
		for (;j <= right;k++, j++)
			sort[k] = arr[j];
	else
		for (;i <= mid;k++, i++)
			sort[k] = arr[i];

	//�ӽ� �迭�� ����� ���ĵ� ���Ҹ� ������ �迭�� �ű��.
	for (int p = left;p <= right;p++)
		arr[p] = sort[p];
}
//�������� ����� �̿��� ��������
int MergeSort(int arr[], int left, int right)
{
	//left == right�� ���Ұ� 1���̹Ƿ� ���� �ʿ䰡 ����.
	if (left < right)
	{
		int mid = (left + right) / 2;
		//�迭�� ���ҽ�Ų��.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		//���ҽ�Ų �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = { 9,1,3,2,10,4,8,7,5,6 };
	int num = 10;

	MergeSort(arr, 0, num - 1);

	//���� Ȯ���� ���� ���
	for (int i = 0; i < num;i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
