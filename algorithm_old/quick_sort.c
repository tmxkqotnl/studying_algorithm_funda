#include <stdio.h>

// 퀵 정렬
// 배열의 원소가 정렬 기준에 따라 위치해야할 곳에 저장시킨다.
// 내림차순
void QuickSort(int arr[], int left, int right)
{
	int i, j, pivot, temp;

	//원소가 1개이거나 인덱스가 범위를 벗어나면 탈출한다.
	if (left >= right)
		return;

	i = left + 1;
	j = right;
	pivot = left;

	while (i <= j)
	{
		// 처음부터 pivot 값 보다 큰 값을 찾는다.
		while (i <= right && arr[i] < arr[pivot]) i++;
		// 마지막부터 pivot 값 보다 작은 값을 찾는다.
		while (j > left && arr[j] > arr[pivot]) j--;

		//만약 교차하지 않았다면 탐색중이던 값을 서로 바꿔준다.
		if (i < j)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	//두 인덱스가 교차했으므로 pivot 값을 알맞은 위치(j)에 저장시킨다.
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;

	// 나머지 원소도 pivot을 기준으로 나눠서 정렬한다.
	QuickSort(arr, left, j - 1);
	QuickSort(arr, j + 1, right);
}

int main()
{
	const int num = 10;
	int arr[] = { 10,1,3,9,2,4,6,5,7,8 };

	QuickSort(arr, 0, num - 1);

	//정렬의 확인을 위한 배열 출력
	for (int i = 0; i < num;i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}