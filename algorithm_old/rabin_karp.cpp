#include <iostream>
#include <vector>

using namespace std;

// ��� ī�� �˰���
// �ؽ� ���� �̿��� ���ڿ��� ã�´�.
// �ؽ� ���� �ش� ���ڿ��� �ƽ�Ű�ڵ忡 �ڸ����� 2�� n������ ���� ���� �� ���̴�.

void findString(string parent, string pattern)
{
	int parentSize = parent.size();
	int patternSize = pattern.size();
	
	int parentHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i <= parentSize - patternSize; i++)
	{
		// i==0 �� �� �� ���ڿ��� �ؽ����� �ʱ�ȭ�Ѵ�.
		if (i == 0)
		{
			for (int j = 0; j < patternSize; j++)
			{
				parentHash = parentHash + parent[patternSize - 1-j]*power;
				patternHash = patternHash + pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		else
		{
			// ������ ���̸�ŭ�� �ش��ϴ� �ؽ����� ���ؾ��Ѵ�.
			// ���� �پ�� �ؽ� ���� ���ְ� ���� �þ �ؽ����� �� ���ش�.
			parentHash = parent[patternSize - 1 + i] + 2 * (parentHash-power * parent[i-1]);
		}

		bool finish = false;
		if (parentHash == patternHash)
		{
			finish = true;
			// �ؽ� ���� �ߺ��Ǵ� ��츦 ����Ͽ� �� �� �� �˻��Ѵ�.
			for (int j = 0; j < patternSize; j++)
				if (parent[i + j] != pattern[j])
				{
					finish = false;
					break;
				}
		}

		if (finish)
			cout << i + 1 << endl;
	}
}

int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(parent, pattern);

	return 0;
}

// �߰� ����
// �ؽ� �� ������ 2�� ���ϴ� ��� �ٸ� ���� �־ �ȴ�.
// ������ �ؽ� ���� ��ġ ���θ� Ȯ���ϱ� ���� MOD(������ ����)�� �ϴ� �� �Ϲ����� ����.