#include <string>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    queue<int> pq; // 차례대로 덱에 삽입할 때 사용할 큐
    deque<pair<int, pair<int, int>>> dq; // 주식 가격, {가격이 떨어진지 여부, 시간} 쌍으로 구성된 덱
    vector<int> answer;
    
    for (auto e : prices) pq.push(e);
    int n = prices.size();
    int cp = 0; // 현재 가격
    
    while (n--)
    {
        if (dq.empty() != true)
        {
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq[i].first <= cp) // 매입 금액이 현재 가격보다 높을 경우
                {
                    if (dq[i].second.first == true) // 이전에 떨어졌던 기록이 없다면
                    {
                        dq[i].second.second++;
                    }
                }
                else // 떨어졌으면
                {
                    dq[i].second.first = false;
                }
            }
        }

        // 덱에 큐의 맨 앞에 있는 값을 삽입함
        if (pq.empty() != true)
        {
            dq.push_back({ pq.front(), {true, 0} }); // 문제 조건으로 시간은 0에서 시작함
            cp = pq.front(); pq.pop();
        }
    }
    
    for (auto e : dq)
    {
        answer.push_back(e.second.second);
    }
    
    return answer;
}
