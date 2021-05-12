#include <iostream>

// 소수판별 알고리즘
// 에라토스테네스의 체
void IsPrimeNumber(int num)
{
	// 소수를 기록해줄 배열 동적할당
	int* arr = new int[num+1];
	// 배열을 0으로 초기화
	std::fill_n(arr, num + 1, 0);

	// 소수가 아닐 경우 1로 초기화한다.
	for (int i = 2; i <= num; i++)
		for (int j = i + i; j <= num; j += i)
			arr[j] = 1;
	
	// 2부터 num까지 소수가 아닌 수를 출력한다.
	for (int i = 2; i <= num; i++)
		if (!arr[i])
			std::cout << i << ' ';
}

int main()
{
	IsPrimeNumber(99999);
	return 0;
}