#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100
#define INF 100001

using namespace std;

// 간선 정보를 저장하는 벡터
vector<int> v[MAX];
// c : 용량을 저장하는 배열, f : 유량을 저장하는 배열, d : 경로를 저장하는 배열(바로 앞 노드를 가리킨다.)
int c[MAX][MAX], f[MAX][MAX], d[MAX];
// 노드의 수, 최대 유량
int num = 6, result;

//네트워크 플로우, 최대유량을 구하라.
void maxflow(int start, int end)
{
	// 여러 경로가 나온다.
	while (1)
	{
		// 경로 정보를 초기화한다.
		fill_n(d, MAX, -1);

		queue<int> q;
		q.push(start);
		
		// 목적지까지 경로 탐색 과정
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++)
			{
				int y = v[x][i];
				// 만약 방문하지 않았고, 용량의 여유가 있을 때
				if (d[y] == -1 && c[x][y] - f[x][y] > 0)
				{
					q.push(y);
					// 경로 저장을 위해 노드 정보를 저장한다.
					d[y] = x;
					// 목적지에 도착했다면 탈출한다. 현재 경로에서는 더 이상 찾을 필요가 없기 때문.
					if (y == end) break;
				}
			}
		}
		// 경로 탐색 중에 용량이 부족해 목적지에 도달하지 못한 경우
		if (d[end] == -1) break;

		// 용량에 유량을 더 해주는 과정
		int flow = INF;

		// 배열을 이용해 역으로 경로를 순회하면서 더할 수 있는 최대 유량을 탐색한다.
		for (int i = end; i != start; i = d[i])
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		
		// 최소 유량을 더해준다.
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow; 
			f[i][d[i]] -= flow; // 음의 유량
		}

		result += flow;
	}
}

int main()
{
	// 간선의 정보와 용량 정보를 초기화한다.
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
	// 최대유량 값 출력
	cout << result;
	return 0;
}
