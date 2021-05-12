#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100
#define INF 100001

using namespace std;

// ���� ������ �����ϴ� ����
vector<int> v[MAX];
// c : �뷮�� �����ϴ� �迭, f : ������ �����ϴ� �迭, d : ��θ� �����ϴ� �迭(�ٷ� �� ��带 ����Ų��.)
int c[MAX][MAX], f[MAX][MAX], d[MAX];
// ����� ��, �ִ� ����
int num = 6, result;

//��Ʈ��ũ �÷ο�, �ִ������� ���϶�.
void maxflow(int start, int end)
{
	// ���� ��ΰ� ���´�.
	while (1)
	{
		// ��� ������ �ʱ�ȭ�Ѵ�.
		fill_n(d, MAX, -1);

		queue<int> q;
		q.push(start);
		
		// ���������� ��� Ž�� ����
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++)
			{
				int y = v[x][i];
				// ���� �湮���� �ʾҰ�, �뷮�� ������ ���� ��
				if (d[y] == -1 && c[x][y] - f[x][y] > 0)
				{
					q.push(y);
					// ��� ������ ���� ��� ������ �����Ѵ�.
					d[y] = x;
					// �������� �����ߴٸ� Ż���Ѵ�. ���� ��ο����� �� �̻� ã�� �ʿ䰡 ���� ����.
					if (y == end) break;
				}
			}
		}
		// ��� Ž�� �߿� �뷮�� ������ �������� �������� ���� ���
		if (d[end] == -1) break;

		// �뷮�� ������ �� ���ִ� ����
		int flow = INF;

		// �迭�� �̿��� ������ ��θ� ��ȸ�ϸ鼭 ���� �� �ִ� �ִ� ������ Ž���Ѵ�.
		for (int i = end; i != start; i = d[i])
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		
		// �ּ� ������ �����ش�.
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow; 
			f[i][d[i]] -= flow; // ���� ����
		}

		result += flow;
	}
}

int main()
{
	// ������ ������ �뷮 ������ �ʱ�ȭ�Ѵ�.
	v[1].push_back(2);
	v[2].push_back(1);
	c[1][2] = 12;
	
	v[1].push_back(4);
	v[4].push_back(1);
	c[1][4] = 11;

	v[2].push_back(3);
	v[3].push_back(2);
	c[2][3] = 6;

	v[2].push_back(4);
	v[4].push_back(2);
	c[2][4] = 3;

	v[2].push_back(5);
	v[5].push_back(2);
	c[2][5] = 9;
	
	v[2].push_back(6);
	v[6].push_back(2);
	c[2][6] = 9;

	v[3].push_back(6);
	v[6].push_back(3);
	c[3][6] = 8;

	v[4].push_back(5);
	v[5].push_back(4);
	c[4][5] = 9;

	v[5].push_back(3);
	v[3].push_back(5);
	c[5][3] = 3;

	v[5].push_back(6);
	v[6].push_back(5);
	c[5][6] = 4;

	maxflow(1, 6);
	// �ִ����� �� ���
	cout << result;
	return 0;
}
