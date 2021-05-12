#include <iostream>
#include <vector>
// 공통 부모 노드 구하기


// 노드의 개수
#define NUM 100
// 최대 층의 개수
#define LOG 12
using namespace std;
// 노드의 숫자 n
int n, m;
// 인덱스에 해당하는 깊이를 저장
int d[NUM];
// 노드 방문 여부를 저장
bool c[NUM];
// 노드 간선 정보를 저장
vector<int> a[NUM];
// 노드의 층별 부모를 저장
int parent[NUM][LOG];

void dfs(int x, int depth)
{
	// 방문을 기록
	c[x] = true;
	// 현재 방문 중인 노드의 깊이 정보를 저장
	d[x] = depth;
	// 이어져 있는 노드 방문
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// 방문하지 않았다면
		if (!c[y])
		{
			// y의 바로 윗 부모 노드 정보 저장
			parent[y][0] = x;
			dfs(y, depth + 1);
		}
	}
}

void setParent()
{
	// 기본적인 부모 정보 저장
	dfs(0, 0);
	// 2^i번째 부모 노드를 저장
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
	// 두 깊이 중 큰 값을 찾아 y로 지정
	if (d[x] > d[y])
		swap(x, y);

	// 높이가 같도록 y의 부모로 이동
	for(int i=LOG-1;i>=0;i--)
	{
		if (d[y] - d[x] >= (1 << i))
			y = parent[y][i];
	}
	// 두 노드 중 하나가 다른 하나의 부모 노드인 경우
	if (x == y) return x;

	// 같은 부모 노드가 나올 때 까지 부모 노드로 거슬러 올라간다.
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