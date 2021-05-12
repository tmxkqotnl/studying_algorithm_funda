#include <iostream>
#include <vector>
#include <queue>

// �Ÿ������� �ʱ�ȭ ������ ��ũ��
#define INF 99999

using namespace std;

// ����� ���� 
const int num = 6;
// �̾��� ���� �Ÿ� ������ ������ ����
vector<pair<int, int>> v[7];
// ���������κ��� �ش� �������� �Ÿ�
int d[7];

void dijkstra(int start)
{
	//�켱���� ť�� �̿��Ѵ�.
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	d[start] = 0;

	while (!pq.empty())
	{
		// ���� ��忡 ���� ������ �����ϰ�
		int cur = pq.top().first;
		int dis = -pq.top().second;
		// �湮�Ͽ����Ƿ� �����ش�.
		pq.pop();

		// �ִܰŸ��� �ƴ� ���
		if (dis > d[cur])
			continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			//���� ���� ������ ��带 �湮�Ѵ�.
			int next = v[cur][i].first;
			int nextdis = dis+v[cur][i].second;

			// ���� ������ �˰��ִ� �Ÿ����� �� ���
			if (nextdis < d[next])
			{
				d[next] = nextdis;
				// �켱���� ť�� Ư���� �̿��Ͽ� ������ ���� ���� �� ���� ���� �����.
				pq.push(make_pair(next, -nextdis));
			}
		}
	}
}

int main() 
{
	// �Ÿ����� �迭 �ʱ�ȭ
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