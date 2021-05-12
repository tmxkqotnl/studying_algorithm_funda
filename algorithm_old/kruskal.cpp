#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// ����� ����
int n = 7;
// ������ ����
int e = 11;

// ���� ������ ����ġ(�Ÿ�)�� ������ ��ü
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

	// ����ġ(�Ÿ�)�� �������� ������������ �����ϱ� ���� ������ �������̵� 
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

// ũ�罺Į �˰���, �ּ� ��� ���� Ʈ��. 
int main()
{
	// ���� ���� �Է�
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

	// ����ġ�� �������� ������������ ����. �ᱹ ����ġ�� ���� ���� ������ ���� Ȯ���ϰԵȴ�.
	sort(v.begin(), v.end());

	// ����Ŭ�� ������ �ʰ� �����ϱ� ���� ������ �迭
	int set[8];
	for (int i = 1; i < 8; i++)
		set[i] = i;

	// ����ġ�� ��
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// ���� �׷����� ������ �ʴ´ٸ� ��带 �̾��ش�.
		if (!findParent(set, v[i].node[0], v[i].node[1]))
		{
			unionParent(set, v[i].node[0], v[i].node[1]);
			sum += v[i].weight;
		}
	}
	// ����ġ�� �� ���
	cout << sum << endl;

	return 0;
}