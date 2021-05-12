#include <iostream>
#include <vector>

using namespace std;

std::vector<int> v;

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		v.push_back(c);
	}

	int result = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		result += n / v[i];
		n %=v[i];
	}

	cout << result << endl;
	return 0;
}