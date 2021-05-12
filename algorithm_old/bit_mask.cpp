#include <iostream>

using namespace std;

// int형 변수의 비트를 보여준다.
void show(int* a)
{
	for (int i = 32; i > 0; i--)
		cout << ((*a&(1<<i-1)) ? 1 : 0);
}
// 변수의 비트를 0으로 초기화한다.
void init(int* a)
{
	*a = 0;
}
// 변수의 비트를 모두 1으로 갱신한다.
void full(int* a)
{
	*a = -1;
}
// i 번째 인덱스의 비트 값을 0으로 갱신한다.
void drop(int* a, int i)
{
	*a &= ~(1 << i);
}
// i 번째 인덱스의 비트 값을 1으로 갱신한다.
void set(int* a, int i)
{
	*a |= (1 << i);
}
// i 번째 인덱스의 비트 값을 확인한다.
bool isSet(int* a, int i)
{
	return (*a & (1 << i));
}
// i 번째 인덱스의 비트 값을 토글한다.
void toggle(int* a, int i)
{
	*a ^= (1 << i);
}
// 변수의 마지막 1 비트 수를 구한다.
int getLast(int* a)
{
	return (*a&-*a);
}

// 마지막 비트 1을 반전시킨다.
void dropLast(int* a)
{
	*a &= (*a - 1);
}

int main()
{
	int a;

	init(&a);
	show(&a);
	cout << endl;

	full(&a);
	show(&a);
	cout << endl;

	drop(&a, 5);
	show(&a);
	cout << endl;

	set(&a, 5);
	show(&a);
	cout << endl;

	cout << "5 is " << isSet(&a, 5) << endl;

	dropLast(&a);
	dropLast(&a);
	dropLast(&a);

	show(&a);
	cout << endl;

	cout << getLast(&a);

	return 0;
}
