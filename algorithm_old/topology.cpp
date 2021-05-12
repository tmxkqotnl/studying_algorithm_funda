#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ����� ��
const int n = 7;
// ����� ���� ������ ������ ����
vector<int> v[8];
// ���� ������ ������ �迭
int inDegree[8] = { 0, };

// �������� ������ �������ִ� �۾��� ���ʴ�� �����Ѵٰ� �Ҷ� �� ������ �˷�(����)�ش�.
void topology()
{
	// �湮�� ��带 ������ ť
	queue<int> q;
	// ������ ������ �迭
	int result[8];

	// �ʱ⿡ ���������� 0��, ��, �������� ã�Ƽ� ť�� �ִ´�.
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0)
			q.push(i);

	// ��� ����� ������ �����ֱ� ���ؼ� ����� ������ŭ �ݺ��Ѵ�.
	for (int i = 1; i <= n; i++)
	{
		// ���� ����Ŭ�� ���� ���������� ��� 0�� �ƴϰ� �� ���
		if (q.empty())
			return;

		// �湮�ϰ� �ִ� ��带 üũ���ش�.
		int x = q.front();
		result[i] = x;
		q.pop();

		// ������ ���� ���ϴ� ������ �����Ѵ�.
		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];
			// ���������� ���� ����� ���������� 0�̶�� ť�� ����ִ´�.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	// ������ ������ �迭 ���
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