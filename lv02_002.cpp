# 프로그래머스 코딩테스트 연습
# Level 2: 괄호 회전하기

#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<char> stk;

int solution(string s) {
    int answer = 0;
	int endpos = s.length();
	for (size_t i = 0; i < s.length(); i++)
	{
		bool chk = true;
		while (!stk.empty()) stk.pop(); // 스택을 초기화한다.
		string cs = s.substr(i, endpos) + s.substr(0, i); // 문자열을 돌려본다.
		for (size_t j = 0; j < cs.length(); j++)
		{
			if ((cs[j] == '}' || cs[j] == ']' || cs[j] == ')'))
			{
				if (stk.empty())
				{
					chk = false;
					break; // 무조건 올바르지 않은 괄호쌍인 경우는 제외한다.
				}
				else
				{
					if ((cs[j] == '}' && stk.top() == '{') ||
						(cs[j] == ']' && stk.top() == '[') ||
						(cs[j] == ')' && stk.top() == '(')) // 올바른 괄호 조합의 경우
					{
						stk.pop(); // 제거한다.
					}
					else // 그 밖의 경우는 올바르지 않은 괄호쌍
					{
						chk = false;
						break;
					}
				}
			}
			else // 여는 괄호의 경우 일단 집어넣는다.
			{
				stk.push(cs[j]);
			}
		}
		if (chk == true && stk.empty()) answer++;
	}
    return answer;
}
