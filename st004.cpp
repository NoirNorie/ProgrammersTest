#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;

int solution(string s)
{
	int answer = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (stk.empty() == true)
		{
			stk.push(s[i]);
		}
		else
		{
			if (stk.top() == s[i]) stk.pop();
			else stk.push(s[i]);
		}
	}

	while (stk.empty() != true)
	{
		char current = stk.top(); stk.pop();
		if (stk.empty() == true) // 스택에 1개 밖에 없었다면
		{
			answer = 0;
			break;
		}
		else
		{
			if (stk.top() == current) stk.pop();
			else 
			{
				answer = 0;
				break;
			}
		}
	}

    return answer;
}

//bool cut(string &s) // 노가다로 푸는 방법
//{
//    int idx = 0;
//
//    while (idx != s.length())
//    {
//        if (s[idx] == s[idx + 1])
//        {
//            s.erase(idx, 2);
//            cout << s << '\n';
//            idx = 0;
//        }
//        else idx++;
//    }
//    if (s.length() == 0) return true;
//    else return false;
//}
//
//
//int main()
//{
//    string s = "cdcd";
//
//    if (cut(s) == true) cout << 1 << '\n';
//    else cout << 0 << '\n';
//
//    return 0;
//}
