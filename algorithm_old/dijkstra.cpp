#include <iostream>
#include <vector>
#include <queue>

// 거리정보를 초기화 시켜줄 메크로
#define INF 99999

using namespace std;

// 노드의 개수 
const int num = 6;
// 이어진 노드와 거리 정보를 저장할 벡터
vector<pair<int, int>> v[7];
// 시작점으로부터 해당 노드까지의 거리
int d[7];

void dijkstra(int start)
{
	//우선순위 큐를 이용한다.
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	d[start] = 0;

	while (!pq.empty())
	{
		// 현재 노드에 대한 정보를 저장하고
		int cur = pq.top().first;
		int dis = -pq.top().second;
		// 방문하였으므로 꺼내준다.
		pq.pop();

		// 최단거리가 아닐 경우
		if (dis > d[cur])
			continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			//현재 노드와 인접한 노드를 방문한다.
			int next = v[cur][i].first;
			int nextdis = dis+v[cur][i].second;

			// 만약 기존에 알고있던 거리보다 긴 경우
			if (nextdis < d[next])
			{
				d[next] = nextdis;
				// 우선순위 큐의 특성을 이용하여 절댓값이 작은 값이 맨 위로 오게 만든다.
				pq.push(make_pair(next, -nextdis));
			}
		}
	}
}

int main() 
{
	// 거리정보 배열 초기화
	fill_n(d, num + 1, INF);

	v[1].push_back(make_pair(2, 2));
	v[1].push_back(make_pair(4, 1));
	v[1].push_back(make_pair(3, 5));

	v[2].push_back(make_pair(1, 2));
	v[2].push_back(make_pair(4, 2));
	v[2].push_back(make_pair(3, 3));

	v[3].push_back(make_pair(2, 3));
	v[3].push_back(make_pair(4, 3));
	v[3].push_back(make_pair(5, 1));
	v[3].push_back(make_pair(6, 5));

	v[4].push_back(make_pair(1, 1));
	v[4].push_back(make_pair(2, 2));
	v[4].push_back(make_pair(3, 3));
	v[4].push_back(make_pair(5, 1));

	v[5].push_back(make_pair(3, 1));
	v[5].push_back(make_pair(4, 1));
	v[5].push_back(make_pair(6, 2));

	v[6].push_back(make_pair(5, 2));
	v[6].push_back(make_pair(3, 5));
	
	dijkstra(1);
	for (int i = 1; i <= num; i++)
		cout << d[i] << ' ';
	return 0;
}