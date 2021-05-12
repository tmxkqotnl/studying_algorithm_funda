// ���� SCC�� ���ϴ� �� ������ ���� ������ �����ϴ�.
// ���� �׷������ ������ SCC�� �����ϴ�.
// ����Ŭ�� ���Ѵ�.
// ���⼭�� Ÿ�� �˰����� �̿��Ѵ�...

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX 10001

using namespace std;

// ��� ���� ������ ������ ����
vector<int> a[MAX];
// ����Ŭ�� ������ ����
vector<vector<int>> scc;
// dfs�� �̿��� ����
stack<int> s;
// ��带 �˻��ߴ��� üũ�ϱ� ���� �迭
bool finished[MAX];
// ����Ŭ�� Ȯ���� �ֱ� ���� ������ ���� �ִ� �迭 d�� ������ ���� ������ id
int d[MAX], id;

//����Ŭ�� �����Ѵٰ� �����Ѵ�.
int dfs(int x)
{
	s.push(x);
	d[x] = ++id;
	int parent = d[x];
	
	// ��尡 ����Ű�� �ִ� ������ ��带 �湮
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// �湮���� ���� ����� �湮�Ѵ�.
		if (d[y] == 0)parent = min(parent, dfs(y));
		// ó������ ���� �����
		if (!finished[y]) parent = min(parent, d[y]);
	}
	// �湮 �߿� �ᱹ parent ���� ���ƿԴٸ� ������ �������ش�.
	if (parent == d[x])
	{
		// �� ����Ŭ�� ������ ����
		vector<int> temp;
		while (1)
		{
			int t = s.top();
			s.pop();
			temp.push_back(t);
			// ó�� ���
			finished[t] = true;
			// ����Ŭ�� ������ ���(�ڱ� �ڽ�)�� ���´ٸ�
			if (t == x)
				break;
		}
		scc.push_back(temp);
	}

	return parent;
}

int main()
{
	int v = 11;

	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(8);
	a[11].push_back(3);

	// �湮���� ���� ��忡 ���Ͽ� dfs�� �����Ѵ�.
	for (int i = 1; i <= v; i++)
		if (d[i] == 0) dfs(i);

	// ����Ŭ�� ������ش�.
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << ' ';
		cout << endl;
	}

	return 0;
}