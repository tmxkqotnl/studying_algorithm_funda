#include <stdio.h>

int main()
{
	int arr[] = { 1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1 };
	int count[6];

	// ��������� ���� ������ �������̰� �� ���� ���� �� �����ϴ�.

	// ������Ŀ� �̿��� �迭�� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < sizeof(count) / sizeof(int);i++)
		count[i] = 0;

	// �迭�� ���ҿ� �ش��ϴ� �ε����� ���� �������� ����Ѵ�.
	for (int i = 0; i < sizeof(arr) / sizeof(int);i++)
		count[arr[i]]++;

	// �ش� ������ ������ŭ ������� ����Ѵ�.
	for (int i = 1;i < sizeof(count) / sizeof(int);i++)
		for (int j = 0; j < count[i];j++)
			printf("%d ", i);
	
	return 0;
}