#include <iostream>
#include <vector>
// ���� �θ� ��� ���ϱ�


// ����� ����
#define NUM 100
// �ִ� ���� ����
#define LOG 12
using namespace std;
// ����� ���� n
int n, m;
// �ε����� �ش��ϴ� ���̸� ����
int d[NUM];
// ��� �湮 ���θ� ����
bool c[NUM];
// ��� ���� ������ ����
vector<int> a[NUM];
// ����� ���� �θ� ����
int parent[NUM][LOG];

void dfs(int x, int depth)
{
	// �湮�� ���
	c[x] = true;
	// ���� �湮 ���� ����� ���� ������ ����
	d[x] = depth;
	// �̾��� �ִ� ��� �湮
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// �湮���� �ʾҴٸ�
		if (!c[y])
		{
			// y�� �ٷ� �� �θ� ��� ���� ����
			parent[y][0] = x;
			dfs(y, depth + 1);
		}
	}
}

void setParent()
{
	// �⺻���� �θ� ���� ����
	dfs(0, 0);
	// 2^i��° �θ� ��带 ����
	for (int j = 1; j < LOG; j++)
	{
		for (int i = 0; i < n; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x, int y)
{
	// �� ���� �� ū ���� ã�� y�� ����
	if (d[x] > d[y])
		swap(x, y);

	// ���̰� ������ y�� �θ�� �̵�
	for(int i=LOG-1;i>=0;i--)
	{
		if (d[y] - d[x] >= (1 << i))
			y = parent[y][i];
	}
	// �� ��� �� �ϳ��� �ٸ� �ϳ��� �θ� ����� ���
	if (x == y) return x;

	// ���� �θ� ��尡 ���� �� ���� �θ� ���� �Ž��� �ö󰣴�.
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (parent[x][i] != parent[y][i])
		{
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	return parent[x][0];
}


int main()
{
	n = 21;

	a[0].push_back(1);
	a[1].push_back(0);

	a[0].push_back(2);
	a[2].push_back(0);

	a[1].push_back(3);
	a[3].push_back(1);

	a[1].push_back(4);
	a[4].push_back(1);

	a[2].push_back(5);
	a[5].push_back(2);

	a[2].push_back(6);
	a[6].push_back(2);

	a[3].push_back(7);
	a[7].push_back(3);

	a[3].push_back(8);
	a[8].push_back(3);

	a[4].push_back(9);
	a[9].push_back(4);

	a[4].push_back(10);
	a[10].push_back(4);

	a[4].push_back(11);
	a[11].push_back(4);

	a[8].push_back(12);
	a[12].push_back(8);

	a[8].push_back(13);
	a[13].push_back(8);

	a[9].push_back(14);
	a[14].push_back(9);

	a[10].push_back(15);
	a[15].push_back(10);

	a[13].push_back(16);
	a[16].push_back(13);

	a[13].push_back(17);
	a[17].push_back(13);

	a[14].push_back(18);
	a[18].push_back(14);

	a[15].push_back(19);
	a[19].push_back(15);

	a[17].push_back(20);
	a[20].push_back(17);

	setParent();

	cout << "5-7 : " << LCA(5, 7) << endl;
	cout << "15-20 : " << LCA(15, 20) << endl;
	cout << "16 -17 : " << LCA(16, 17) << endl;
	cout << "10-9 : " << LCA(10, 9) << endl;
	cout << "3-17 : " << LCA(3, 17) << endl;

	return 0;
}