#include <stdio.h>

int main()
{
	int arr[] = { 1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1 };
	int count[6];

	// 계수정렬은 값의 범위가 한정적이고 그 수가 많을 때 유용하다.

	// 계수정렬에 이용할 배열을 초기화한다.
	for (int i = 0; i < sizeof(count) / sizeof(int);i++)
		count[i] = 0;

	// 배열의 원소에 해당하는 인덱스의 값을 증가시켜 기록한다.
	for (int i = 0; i < sizeof(arr) / sizeof(int);i++)
		count[arr[i]]++;

	// 해당 원소의 개수만큼 순서대로 출력한다.
	for (int i = 1;i < sizeof(count) / sizeof(int);i++)
		for (int j = 0; j < count[i];j++)
			printf("%d ", i);
	
	return 0;
}