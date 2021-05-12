#include <iostream>
#include <vector>

using namespace std;

// ����� ����
int num = 7;
// ��� ������ ������ ����
vector<int> v[8];
// �湮 ������ ������ �迭
int c[8];

//depth_first_search, ���� �켱 Ž��
//STL stack�� ������� ���� ����, ��ǻ�Ͱ� ���������� ������ ������ ����Ѵ�. ��, ���⼭, ���� �ٱ��� �Լ��� �� �������� ����ȴ�.
void dfs(int x)
{
	// �湮�� ����� �Լ��� Ż���Ѵ�.
	if (c[x])
		return;

	// �湮�� ����Ѵ�.
	c[x] = true;
	// �湮�� ��� ���
	cout << x << ' ';
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		// ������ ��忡 ���ؼ� dfs�� �����Ѵ�.
		dfs(y);
	}
}
int main()
{
	//���� ������ �����Ѵ�.
	v[1].push_back(2);
	v[1].push_back(3);

	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(4);
	v[2].push_back(5);

	v[3].push_back(1);
	v[3].push_back(2);
	v[3].push_back(6);
	v[3].push_back(7);

	v[4].push_back(2);
	v[4].push_back(5);

	v[5].push_back(2);
	v[5].push_back(4);

	v[6].push_back(3);
	v[6].push_back(7);

	v[7].push_back(3);
	v[7].push_back(6);

	dfs(1);

	return 0;
}