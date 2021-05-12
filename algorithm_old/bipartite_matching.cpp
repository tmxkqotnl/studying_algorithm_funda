#include <iostream>
#include <vector>

// 결과적으로 모든 노드가 매칭이 되도록 한다.

#define MAX 100
using namespace std;

// i번 노드를 점유한 노드를 기록하는 배열
int d[MAX];
// 노드가 다른 한 파티의 어느 노드를 방문했는지 체크하는 배열
bool c[MAX];
// 노드 연결 정보를 기록하는 벡터
vector<int> v[MAX];
// 노드 개수 정보
int n = 3;
int m, s;

bool dfs(int x)
{
	//dfs를 이용하여 매칭을 기록해준다.
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		// 이미 매칭이 끝난 노드는 연산할 필요가 없다.
		if (c[y]) continue;

		// 매칭을 기록한다.
		c[y] = true;
		// 아직 점유하지 않았거나 이미 점유하고 있는 노드가 다른 곳을 점유할 수 있는지 확인
		if (d[y] == 0 || dfs(y))
		{
			// 어느 노드가 매칭을 했는지 기록한다.
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	// 노드 정보 초기화
	v[1].push_back(1);
	v[1].push_back(2);
	v[1].push_back(3);
	v[2].push_back(1);
	v[3].push_back(2);

	// 노드에 대한 매칭 정보를 갱신
	for (int i = 1; i <= n; i++)
	{
		fill_n(c, MAX, false);
		if (d[i] == 0) dfs(i);
	}
	int count = 0;//매칭된 수를 기록
	for (int i = 1; i < MAX; i++)
	{
		if (d[i] != 0)
		{
			count++;
			cout << d[i] << "->" << i << endl;
		}
	}
	cout << count << endl;

	return 0;
}
