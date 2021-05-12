#include <iostream>
#include <vector>

using namespace std;

// Knuth-Morris-Pratt
// ���λ�(�� ���ڿ�)�� ���̻�(�� ���ڿ�)�� �̿��Ͽ� �ݺ��Ǵ� ������ �󸶳� ���� �� �ִ��� �Ǻ��Ѵ�.
// ��ġ���� ������ �ٷ� �Ѿ��..


// ���̺� ����
vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	// ���λ� �ε���
	int j = 0;
	
	// i ���̻� �ε���
	// ���λ�� ���̻簡 ��ġ�ϴ� ���̸� ã�´�.(���̺� ���� ���� ū ���� �� ���̰� �ȴ�.)
	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];

		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}

	return table;
}

void KMP(string parent, string pattern)
{
	// ���̺� �����Ͽ� ������ ���λ�� ���̻翡 ���� ���̿� �ε����� ã�Ƴ��ұ� ������
	// �ش� �ε����� ������ �� ���� ã�� �� �ְ� �ȴ�.
	vector<int> table = makeTable(pattern);

	int parentSize = parent.size();
	int patternSize = pattern.size();

	// ������ �ε��� j
	int j = 0;
	// �˻� ����� ���ڿ��� �ε��� i
	for (int i = 0; i < parent.size(); i++)
	{
		// ���� �ʴٸ� �ε����� ������ �����ش�.
		// ���Ⱑ ������ �߿��ѵ�, ���� �Ϲ����� �ݺ� ���ڿ� Ž�������� ��� ���ڿ����� ���ڿ��� �� �� ã���� �״�� ������.
		// ������ KMP�� ��� while���� ���� ��ġ�ϴ� ���������� �ε����� ������ �ű�� �ȴ�.
		// �ᱹ, Ž�� ��� ���ڿ��� �����ִ� ��ġ�ϴ� ��� Ÿ�� ���ڿ��� ã�� �� �ִ�.
		// ���̻��� ��ġ���� j���� ������ ���� �Ǵµ� �̹� ���̺� ����� ���λ� �ε��� ��ġ�� j�� ���Եȴ�.
		// �׷��� ���� ������ while���� �۵��� �ʿ� ���� j�� ���� �� ���� ������ �� �� �ִ�.
		while (j > 0 && parent[i] != pattern[j])
			j = table[j - 1];

		if (parent[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				cout << "FOUND" << ' ' << i-patternSize+2 << endl;
				j = table[j];
			}
			else
			{
				j++;
			}
		}
	}
}

int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	KMP(parent, pattern);

	return 0;
}