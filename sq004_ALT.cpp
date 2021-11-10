#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    
    stack<pair<int, int>> s; // 가격과 인덱스를 저장할 스택
    vector<int> answer(prices.size(), -1); // 결과
    int n = prices.size();
    
    for (int i = 0; i < prices.size(); i++)
    {
        if (s.empty() == true) // 스택이 비었으면
        {
            s.push({ prices[i], i }); // 스택에 가격과 인덱스를 기록한다.
        }
        else
        {
            if (s.top().first <= prices[i]) // 현재 가격이 스택의 맨 위 값 이상일 경우
            {
                s.push({ prices[i], i });
            }
            else
            {
                while (s.empty() != true && s.top().first > prices[i])
                {
                    answer[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push({ prices[i], i });
            }
        }
    }
    while (s.empty() != true)
    {
        answer[s.top().second] = n - s.top().second - 1;
        s.pop();
    }
    
    return answer;
}
