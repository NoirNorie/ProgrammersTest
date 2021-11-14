#include <string>
#include <vector>
#include <deque>
using namespace std;

string solution(string number, int k) {
    string s = number;
    int r = 0; int i = 0;
    deque<int> dq;

    while (i != s.length())
    {
        if (dq.empty() == true) // 초기 상태에서 동작 또는 덱이 빈 경우 동작
        {
            dq.push_back(s[i++] - '0');
        }
        else
        {
            while (dq.back() < (s[i] - '0') && k > 0) // 제거 횟수를 다 소모하거나 작은 수가 앞에 있는 경우에 
            {
                dq.pop_back(); k--;
                if (dq.empty() == true) break;
            }
            dq.push_back(s[i++] - '0');
        }
    }

    if (k > 0) // 제거 횟수가 남은 경우 뒤의 숫자를 제거하는 것이 가장 큰 수를 만들 수 있다.
    {
        while (k--)
        {
            dq.pop_back();
        }
    }

    string answer = "";

    for (int i = 0; i < dq.size(); i++)
    {
        answer += to_string(dq[i]);
    }
    return answer;
}
