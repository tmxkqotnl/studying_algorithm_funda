#include <stdio.h>
#define MAX 9999

int main()
{
	int i, j,k = 0, temp, min;
	const int num = 10;
	int arr[] = { 10,1,9,2,4,3,6,5,7,8 };

	// 선택정렬
	// 가장 작은 원소를 앞으로 보낸다.
	for (i = 0; i < num;i++)
	{
		//가장 작은 원소를 찾기 위한 min
		min = MAX;
		for (j = i;j < num;j++)
		{
			if (min > arr[j])
			{
				//원소의 인덱스를 기록하고 min을 초기화한다.
				k = j;
				min = arr[j];
			}
		}
		// 가장 작은 값을 찾았으므로 i의 위치에 저장한다.
		temp = arr[k];
		arr[k] = arr[i];
		arr[i] = temp;
	}
	
	// 정렬 확인을 위한 배열 출력
	for (int p = 0;p < num;p++)
		printf("%d ", arr[p]);
	printf("\n");

	return 0;
}