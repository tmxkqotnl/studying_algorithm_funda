#include <iostream>

#define INF 99999

using namespace std;
int num = 4;

// 초기 거리 정보를 저장한 배열
int a[4][4] = {
	{0,5,INF,8},
{7,0,9,INF},
{2,INF,0,4},
{INF,INF,3,0}
};

// 플로이드 와샬, 다이나믹 프로그래밍을 이용
// 모든 정점으로 가는 최단 거리를 구한다.
void floydWarshall()
{
	// 거리 정보를 저장할 배열
	int d[4][4];

	// 배열 초기화
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			d[i][j] = a[i][j];
	
	for (int k = 0; k < num; k++) // k : 거쳐가는 노드
		for (int i = 0; i < num; i++) // i : 시작 노드
			for (int j = 0; j < num; j++) // j : 종착 노드
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
	
	// 거리 정보 출력
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