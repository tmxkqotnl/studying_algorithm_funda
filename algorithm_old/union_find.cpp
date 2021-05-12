#include <iostream>

//union_find, 합집합을 찾거나 같은 그래프에 속하는지 판별하는 알고리즘

// 노드의 부모를 찾는다. 속해있는 그래프를 찾는다.
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	else
		return parent[x] = getParent(parent, parent[x]);
}
// 노드의 부모를 합친다. 두 노드(그래프)를 잇는다.
void unionParent(int parent[], int x, int y)
{
	int getx = getParent(parent, x);
	int gety = getParent(parent, y);

	if (getx > gety)
		parent[x] = gety;
	else
		parent[y] = getx;
}
// 노드의 부모가 서로 일치하는지 확인한다. 서로 같은 그래프에 속해 있는지 확인한다.
int findParent(int parent[], int x, int y)
{
	int getx = getParent(parent, x);
	int gety = getParent(parent, y);

	if (getx == gety)
		return true;
	else
		return false;
}

int main()
{
	// 노드의 부모 정보를 저장할 배열
	int p[9];
	for (int i = 1; i <= 8; i++)
		p[i] = i;
	
	// 노드를 이어준다.
	unionParent(p, 1, 2);
	unionParent(p, 2, 3);
	unionParent(p, 3, 4);
	unionParent(p, 5, 6);
	unionParent(p, 6, 7);
	unionParent(p, 7, 8);

	// 노드가 이어져 있는지 확인한다.
	std::cout << "1-5 ? : " << findParent(p, 1, 5) << std::endl;
	unionParent(p, 1, 5);
	std::cout << "1-5 ? : " << findParent(p, 1, 5) << std::endl;

	return 0;
}
