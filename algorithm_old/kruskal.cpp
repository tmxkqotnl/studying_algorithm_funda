#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 노드의 개수
int n = 7;
// 간선의 개수
int e = 11;

// 간선 정보와 가중치(거리)를 저장할 객체
class Edge {
public:
	int node[2];
	int weight;

	Edge(int n1, int n2, int w)
	{
		this->node[0] = n1;
		this->node[1] = n2;
		this->weight = w;
	}

	// 가중치(거리)를 기준으로 오름차순으로 정렬하기 위한 연산자 오버라이딩 
	bool operator<(Edge& e)
	{
		return this->weight < e.weight;
	}
};

vector<Edge> v;

int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	else
		return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int x, int y)
{
	int getx = getParent(parent, x);
	int gety = getParent(parent, y);

	if (getx > gety)
		parent[x] = gety;
	else
		parent[y] = getx;
}
bool findParent(int parent[], int x, int y)
{
	int getx = getParent(parent, x);
	int gety = getParent(parent, y);
	
	if (getx == gety)
		return true;
	else
		return false;
}

// 크루스칼 알고리즘, 최소 비용 신장 트리. 
int main()
{
	// 간선 정보 입력
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(1,7, 12));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 7, 73));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));

	// 가중치를 기준으로 오름차순으로 정렬. 결국 가중치가 가장 작은 값부터 먼저 확인하게된다.
	sort(v.begin(), v.end());

	// 싸이클이 생기지 않게 방지하기 위한 합집합 배열
	int set[8];
	for (int i = 1; i < 8; i++)
		set[i] = i;

	// 가중치의 합
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// 같은 그래프에 속하지 않는다면 노드를 이어준다.
		if (!findParent(set, v[i].node[0], v[i].node[1]))
		{
			unionParent(set, v[i].node[0], v[i].node[1]);
			sum += v[i].weight;
		}
	}
	// 가중치의 합 출력
	cout << sum << endl;

	return 0;
}