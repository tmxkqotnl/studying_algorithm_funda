#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방문 정보를 저장하는 배열
int c[8];
// 노드의 개수
int num = 7;
// 노드의 정보를 저장하는 벡터
vector<int> v[8];
// 방문 노드를 저장할 큐
queue<int> q;


//breadth_first_search, 넓이 우선 탐색
void bfs(int start)
{
	// 시작 노드를 방문처리 해준다.
	c[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		// 방문한 노드를 출력
		cout << x << ' ';
		// 방문하고 있는 노드와 연결되어 있는 노드를 확인한다.
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			// 만약 방문하지 않은 노드가 있다면 방문처리 해준다.
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main()
{
	// 노드 정보를 벡터에 저장한다.
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
	
	v[5].push_back(3);
	v[5].push_back(4);

	v[6].push_back(3);
	v[6].push_back(7);

	v[7].push_back(3);
	v[7].push_back(6);

	bfs(1);

	return 0;
}
