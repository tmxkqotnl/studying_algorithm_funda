#include <iostream>
#define NUM 12

// 세그먼트 트리
// 루트노드부터 배열의 범위의 합을 저장한다.
// 루트노드는 배열 전체를 그리고 두 자식 노드는 루트노드의 합의 범위에서 각각 절반의 범위의 합을 가진다.
// BigO = logn

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
// 여기선 임의로 트리의 크기를 잡아줬다.
// 세그먼트 트리에서는 더한 값의 크기를 정해주기 위해서 
// 배열의 원소의 개수보다 크면서 가장 가까운 제곱근에 2를 곱해준 값을 최소로 잡는다.
// 여기서는 12개 이므로 16*2 = 32.
int tree[NUM * 4];

int init(int start, int end, int node)
{
	//터미널 노드에 도착하여 범위가 아닌 한 개의 배열 원소를 가리키므로
	if (start == end)
		return tree[node] = a[start];

	int mid = (start + end) / 2;
	// 세그먼트 트리의 한 노드의 값은 두 자식 노드의 합과 같다.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right)
{
	// 범위 밖의 노드를 보고있다면
	if (start > right || end < left)
		return 0;
	// 범위 안의 노드를 보고있다면
	if (start >= left && end <= right)
		return tree[node];

	// 해당 범위의 노드 값을 더한다.
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, int diff)
{
	// 해당 idx가 속해있지 않은 노드를 보고 있다면
	if(start>idx||end<idx)
		return;

	// 노드의 값을 갱신한다.
	tree[node] += diff;
	// 터미널 노드라면 값을 갱신했으므로
	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main()
{
	init(0, NUM - 1, 1);
	// 배열 인덱스 0부터 11까지의 합
	cout << sum(0, NUM - 1, 1, 0, 11)<<endl;
	// 배열 인덱스 3부터 8까지의 합
	cout << sum(0, NUM - 1, 1, 3, 8)<<endl;

	// 인덱스 5의 값에 -5를 더하여 갱신한다.
	update(0, NUM-1, 1, 5, -5);
	// 갱신된 배열 인덱스 3부터 8까지의 합
	cout << sum(0, NUM - 1, 1, 3, 8) << endl;

	return 0;
}