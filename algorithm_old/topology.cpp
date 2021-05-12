#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 노드의 수
const int n = 7;
// 노드의 연결 정보를 저장할 벡터
vector<int> v[8];
// 진입 차수를 저장할 배열
int inDegree[8] = { 0, };

// 위상정렬 순서가 정해져있는 작업을 차례대로 수행한다고 할때 그 순서를 알려(결정)준다.
void topology()
{
	// 방문한 노드를 저장할 큐
	queue<int> q;
	// 순서를 저장할 배열
	int result[8];

	// 초기에 진입차수가 0인, 즉, 시작점을 찾아서 큐에 넣는다.
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0)
			q.push(i);

	// 모든 노드의 순서를 정해주기 위해서 노드의 개수만큼 반복한다.
	for (int i = 1; i <= n; i++)
	{
		// 만약 싸이클이 생겨 진입차수가 모두 0이 아니게 될 경우
		if (q.empty())
			return;

		// 방문하고 있는 노드를 체크해준다.
		int x = q.front();
		result[i] = x;
		q.pop();

		// 인접한 노드로 향하는 진입을 삭제한다.
		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];
			// 진입차수를 줄인 노드의 진입차수가 0이라면 큐에 집어넣는다.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	// 순서를 저장한 배열 출력
	for (int i = 1; i <= n; i++)
		cout << result[i] << ' ';

}

int main()
{
	v[1].push_back(2);
	inDegree[2]++;
	v[1].push_back(5);
	inDegree[5]++;
	v[2].push_back(3);
	inDegree[3]++;
	v[3].push_back(4);
	inDegree[4]++;
	v[4].push_back(6);
	inDegree[6]++;
	v[5].push_back(6);
	inDegree[6]++;
	v[6].push_back(7);
	inDegree[7]++;

	topology();
	return 0;
}