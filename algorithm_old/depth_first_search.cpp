#include <iostream>
#include <vector>

using namespace std;

// 노드의 개수
int num = 7;
// 노드 정보를 저장할 벡터
vector<int> v[8];
// 방문 정보를 저장할 배열
int c[8];

//depth_first_search, 깊이 우선 탐색
//STL stack을 사용하지 않은 이유, 컴퓨터가 구조적으로 스택의 원리를 사용한다. 즉, 여기서, 가장 바깥의 함수가 맨 마지막에 종료된다.
void dfs(int x)
{
	// 방문한 노드라면 함수를 탈출한다.
	if (c[x])
		return;

	// 방문을 기록한다.
	c[x] = true;
	// 방문한 노드 출력
	cout << x << ' ';
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		// 인접한 노드에 대해서 dfs를 수행한다.
		dfs(y);
	}
}
int main()
{
	//벡터 정보를 저장한다.
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

	v[5].push_back(2);
	v[5].push_back(4);

	v[6].push_back(3);
	v[6].push_back(7);

	v[7].push_back(3);
	v[7].push_back(6);

	dfs(1);

	return 0;
}