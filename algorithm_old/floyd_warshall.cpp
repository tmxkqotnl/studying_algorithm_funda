#include <iostream>

#define INF 99999

using namespace std;
int num = 4;

// �ʱ� �Ÿ� ������ ������ �迭
int a[4][4] = {
	{0,5,INF,8},
{7,0,9,INF},
{2,INF,0,4},
{INF,INF,3,0}
};

// �÷��̵� �ͼ�, ���̳��� ���α׷����� �̿�
// ��� �������� ���� �ִ� �Ÿ��� ���Ѵ�.
void floydWarshall()
{
	// �Ÿ� ������ ������ �迭
	int d[4][4];

	// �迭 �ʱ�ȭ
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			d[i][j] = a[i][j];
	
	for (int k = 0; k < num; k++) // k : ���İ��� ���
		for (int i = 0; i < num; i++) // i : ���� ���
			for (int j = 0; j < num; j++) // j : ���� ���
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
	
	// �Ÿ� ���� ���
	cout.width(-3);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cout << d[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	floydWarshall();
	return 0;
}