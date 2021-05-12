#include <stdio.h>

int main()
{
	const int num = 10;
	int arr[] = { 9,1,2,10,4,3,5,7,6,8 };
	int i, j, temp;

	// 버블정렬
	// 원소의 바로 다음 원소와 비교하면서 정렬한다.
	for (i = 0;i < num;i++)
		for (j = i;j < num-1;j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	
	// 정렬 확인을 위한 배열 출력
	for (int k = 0; k < num;k++)
		printf("%d ", arr[k]);
	printf("\n");

	return 0;
}