#include <iostream>
#define NUM 12

// ���׸�Ʈ Ʈ��
// ��Ʈ������ �迭�� ������ ���� �����Ѵ�.
// ��Ʈ���� �迭 ��ü�� �׸��� �� �ڽ� ���� ��Ʈ����� ���� �������� ���� ������ ������ ���� ������.
// BigO = logn

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
// ���⼱ ���Ƿ� Ʈ���� ũ�⸦ ������.
// ���׸�Ʈ Ʈ�������� ���� ���� ũ�⸦ �����ֱ� ���ؼ� 
// �迭�� ������ �������� ũ�鼭 ���� ����� �����ٿ� 2�� ������ ���� �ּҷ� ��´�.
// ���⼭�� 12�� �̹Ƿ� 16*2 = 32.
int tree[NUM * 4];

int init(int start, int end, int node)
{
	//�͹̳� ��忡 �����Ͽ� ������ �ƴ� �� ���� �迭 ���Ҹ� ����Ű�Ƿ�
	if (start == end)
		return tree[node] = a[start];

	int mid = (start + end) / 2;
	// ���׸�Ʈ Ʈ���� �� ����� ���� �� �ڽ� ����� �հ� ����.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right)
{
	// ���� ���� ��带 �����ִٸ�
	if (start > right || end < left)
		return 0;
	// ���� ���� ��带 �����ִٸ�
	if (start >= left && end <= right)
		return tree[node];

	// �ش� ������ ��� ���� ���Ѵ�.
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, int diff)
{
	// �ش� idx�� �������� ���� ��带 ���� �ִٸ�
	if(start>idx||end<idx)
		return;

	// ����� ���� �����Ѵ�.
	tree[node] += diff;
	// �͹̳� ����� ���� ���������Ƿ�
	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main()
{
	init(0, NUM - 1, 1);
	// �迭 �ε��� 0���� 11������ ��
	cout << sum(0, NUM - 1, 1, 0, 11)<<endl;
	// �迭 �ε��� 3���� 8������ ��
	cout << sum(0, NUM - 1, 1, 3, 8)<<endl;

	// �ε��� 5�� ���� -5�� ���Ͽ� �����Ѵ�.
	update(0, NUM-1, 1, 5, -5);
	// ���ŵ� �迭 �ε��� 3���� 8������ ��
	cout << sum(0, NUM - 1, 1, 3, 8) << endl;

	return 0;
}