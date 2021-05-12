#include <iostream>

#define C1 500
#define C2 100
#define C3 50
#define C4 10

void SimpleGreedy(int num)
{
	int result = 0;

	result += num / C1;
	num %= C1;
	result += num / C2;
	num %= C2;
	result += num / C3;
	num %= C3;
	result += num / C4;
	num %= C4;

	std::cout << result << std::endl;
}

int main()
{
	SimpleGreedy(1650);
	return 0;
}