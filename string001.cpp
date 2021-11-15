#include <string>
#include <vector>
using namespace std;

inline int S_MIN(int a, int b)
{
	return a > b ? b : a;
}

int compress(string s)
{
	int m = 1001;
	if (s.length() == 1) // 길이가 1인 경우 무조건 1임
	{
		return 1;
	}
	for (int i = 1; i <= s.length() / 2; i++) // 1부터 길이의 절반까지 수행해본다.
	{
		string tmp = "";
		int st = 0;
		int idx = st + i;
		int ca = 1;
		while (st + i < s.length())
		{
			if (s.substr(st, i) == s.substr(idx, i)) // 압축 가능한 문자열의 경우
			{
				ca++; idx += i;
			}
			else
			{
				if (ca <= 1) tmp += s.substr(st, i);
				else tmp += (to_string(ca) + s.substr(st, i));
				st = idx;
				ca = 1;
				idx = st + i;
			}
		}

		if (st != s.length()) // 예외처리
		{
			tmp += s.substr(st, s.length());// 남은 값을 모두 사출
		}

		m = S_MIN(m, tmp.length());
	}
	return m;
}

int solution(string s) {
    int answer = compress(s);
    return answer;
}
