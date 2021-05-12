// 같은 SCC에 속하는 두 정점은 서로 도달이 가능하다.
// 무향 그래프라면 무조건 SCC가 가능하다.
// 싸이클에 속한다.
// 여기서는 타잔 알고리즘을 이용한다...

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX 10001

using namespace std;

// 노드 간선 정보를 저장할 벡터
vector<int> a[MAX];
// 싸이클을 저장할 벡터
vector<vector<int>> scc;
// dfs에 이용할 스택
stack<int> s;
// 노드를 검사했는지 체크하기 위한 배열
bool finished[MAX];
// 싸이클을 확인해 주기 위해 고유한 값을 넣는 배열 d와 고유한 값을 지정할 id
int d[MAX], id;

//싸이클이 존재한다고 가정한다.
int dfs(int x)
{
	s.push(x);
	d[x] = ++id;
	int parent = d[x];
	
	// 노드가 가리키고 있는 인접한 노드를 방문
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// 방문하지 않은 노드라면 방문한다.
		if (d[y] == 0)parent = min(parent, dfs(y));
		// 처리되지 않은 노드라면
		if (!finished[y]) parent = min(parent, d[y]);
	}
	// 방문 중에 결국 parent 노드로 돌아왔다면 꺼내서 저장해준다.
	if (parent == d[x])
	{
		// 한 싸이클을 저장할 벡터
		vector<int> temp;
		while (1)
		{
			int t = s.top();
			s.pop();
			temp.push_back(t);
			// 처리 기록
			finished[t] = true;
			// 싸이클의 마지막 노드(자기 자신)를 꺼냈다면
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

	// 방문하지 않은 노드에 한하여 dfs를 수행한다.
	for (int i = 1; i <= v; i++)
		if (d[i] == 0) dfs(i);

	// 싸이클을 출력해준다.
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << ' ';
		cout << endl;
	}

	return 0;
}