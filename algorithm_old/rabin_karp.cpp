#include <iostream>
#include <vector>

using namespace std;

// 라빈 카프 알고리즘
// 해쉬 값을 이용해 문자열을 찾는다.
// 해쉬 값은 해당 문자열의 아스키코드에 자리마다 2의 n제곱을 곱한 값의 총 합이다.

void findString(string parent, string pattern)
{
	int parentSize = parent.size();
	int patternSize = pattern.size();
	
	int parentHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i <= parentSize - patternSize; i++)
	{
		// i==0 일 때 각 문자열의 해쉬값을 초기화한다.
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
			// 패턴의 길이만큼에 해당하는 해쉬값을 구해야한다.
			// 앞의 줄어든 해쉬 값은 빼주고 뒤의 늘어난 해쉬값을 더 해준다.
			parentHash = parent[patternSize - 1 + i] + 2 * (parentHash-power * parent[i-1]);
		}

		bool finish = false;
		if (parentHash == patternHash)
		{
			finish = true;
			// 해쉬 값이 중복되는 경우를 고려하여 한 번 더 검사한다.
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

// 추가 설명
// 해쉬 값 연산을 2를 곱하는 대신 다른 값을 넣어도 된다.
// 하지만 해쉬 값의 일치 여부를 확인하기 위해 MOD(나머지 연산)를 하는 게 일반적인 경우다.