#include <iostream>

// �Ҽ��Ǻ� �˰���
// �����佺�׳׽��� ü
void IsPrimeNumber(int num)
{
	// �Ҽ��� ������� �迭 �����Ҵ�
	int* arr = new int[num+1];
	// �迭�� 0���� �ʱ�ȭ
	std::fill_n(arr, num + 1, 0);

	// �Ҽ��� �ƴ� ��� 1�� �ʱ�ȭ�Ѵ�.
	for (int i = 2; i <= num; i++)
		for (int j = i + i; j <= num; j += i)
			arr[j] = 1;
	
	// 2���� num���� �Ҽ��� �ƴ� ���� ����Ѵ�.
	for (int i = 2; i <= num; i++)
		if (!arr[i])
			std::cout << i << ' ';
}

int main()
{
	IsPrimeNumber(99999);
	return 0;
}