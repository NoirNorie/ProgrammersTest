#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> people = { 70, 80, 50 };
    int limit = 100;
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());
    deque<int> dq(people.begin(), people.end());

    int current_limit = 0;
    while (dq.empty() != true)
    {
        current_limit += dq.front(); dq.pop_front();
        while (dq.empty() != true && current_limit + dq.back() <= limit) // 내림차순으로 정렬한 이유
        {
            current_limit += dq.back(); dq.pop_back(); // 현재 무게에 가벼운 사람을 추가하면 더 많이 태워서 적은 보트를 사용할 수 있다
        }
        answer++;
        current_limit = 0;
    }

    cout << answer << '\n';
}
