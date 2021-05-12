#include <iostream>
#include <algorithm>

//น้มุ 2217

using namespace std;

int a[10001];

int main()
{
	int max = 0, c;
	cin >> c;
	for (int i = 0; i < c; i++)
		cin >> a[i];
	
	sort(a,a+c);

	for (int i = 0; i <c ; i++)
		if (max < a[i] * (c - i))
			max = a[i] * (c - i);
	
	cout << max;

	return 0;
}