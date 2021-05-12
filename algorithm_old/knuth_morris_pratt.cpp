#include <iostream>
#include <vector>

using namespace std;

// Knuth-Morris-Pratt
// 접두사(앞 문자열)와 접미사(뒷 문자열)를 이용하여 반복되는 연산을 얼마나 줄일 수 있는지 판별한다.
// 일치하지 않으면 바로 넘어간다..


// 테이블 생성
vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	// 접두사 인덱스
	int j = 0;
	
	// i 접미사 인덱스
	// 접두사와 접미사가 일치하는 길이를 찾는다.(테이블에 들어가는 가장 큰 값이 그 길이가 된다.)
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
	// 테이블 생성하여 기존에 접두사와 접미사에 대한 길이와 인덱스를 찾아놓았기 때문에
	// 해당 인덱스를 가리켜 더 빨리 찾을 수 있게 된다.
	vector<int> table = makeTable(pattern);

	int parentSize = parent.size();
	int patternSize = pattern.size();

	// 패턴의 인덱스 j
	int j = 0;
	// 검색 대상의 문자열의 인덱스 i
	for (int i = 0; i < parent.size(); i++)
	{
		// 같지 않다면 인덱스를 앞으로 돌려준다.
		// 여기가 굉장히 중요한데, 보통 일반적인 반복 문자열 탐색에서는 대상 문자열에서 문자열을 한 번 찾으면 그대로 끝난다.
		// 하지만 KMP의 경우 while문을 통해 일치하는 구간까지만 인덱스를 앞으로 옮기게 된다.
		// 결국, 탐색 대상 문자열에 속해있는 일치하는 모든 타겟 문자열을 찾을 수 있다.
		// 접미사의 위치부터 j값이 앞으로 오게 되는데 이미 테이블에 저장된 접두사 인덱스 위치가 j에 대입된다.
		// 그러면 굳이 여러번 while문이 작동할 필요 없이 j의 값은 한 번에 앞으로 갈 수 있다.
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