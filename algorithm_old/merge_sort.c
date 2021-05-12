#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//divide and conquer

//분할시킨 배열을 정렬하는 함수
int MergeTwoArea(int arr[], int left, int mid, int right)
{
	int i, j, k;
	//나누어진 배열을 임시로 저장할 배열
	int* sort = (int*)malloc(sizeof(int) * (right+1));
	memset(sort, 0, sizeof(int) * (right + 1));

	i = left;
	j = mid + 1;
	k = left;

	//작은 값부터 차례대로 저장한다.
	while (i <=mid&&j<=right)
	{
		if (arr[i] < arr[j])sort[k++] = arr[i++];
		if (arr[j] < arr[i])sort[k++] = arr[j++];
	}

	//만약 저장하지 못한 원소가 있다면 마저 저장한다.
	if (i > mid)
		for (;j <= right;k++, j++)
			sort[k] = arr[j];
	else
		for (;i <= mid;k++, i++)
			sort[k] = arr[i];

	//임시 배열에 저장된 정렬된 원소를 기존의 배열로 옮긴다.
	for (int p = left;p <= right;p++)
		arr[p] = sort[p];
}
//분할정복 기법을 이용한 병합정렬
int MergeSort(int arr[], int left, int right)
{
	//left == right는 원소가 1개이므로 나눌 필요가 없다.
	if (left < right)
	{
		int mid = (left + right) / 2;
		//배열을 분할시킨다.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		//분할시킨 배열을 정렬한다.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = { 9,1,3,2,10,4,8,7,5,6 };
	int num = 10;

	MergeSort(arr, 0, num - 1);

	//정렬 확인을 위한 출력
	for (int i = 0; i < num;i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
