# 프로그래머스 코딩테스트 연습
# Level 2: 캐시

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;

	if (cacheSize == 0)
	{
		answer += 5 * cities.size();
	}
	else
	{
		for (auto e : cities)
		{
			bool chk = false;

			transform(e.begin(), e.end(), e.begin(), ::toupper);
			for (size_t i = 0; i < dq.size(); i++)
			{
				if (dq[i] == e) // 덱 안에 찾는 값이 있다면
				{
					dq.erase(dq.begin() + i); // 그 위치의 값을 제거한다.
					dq.push_back(e); //새로 집어넣는다.
					answer += 1; // 실행 시간을 더한다.
					chk = true;
					break;
				}
			}
			if (chk == false)
			{
				if (dq.empty() != true && dq.size() == cacheSize) dq.pop_front(); // 맨 앞에 있는 값을 제거한다.
				dq.push_back(e); // 뒤에 값을 삽입한다.
				answer += 5;
			}
		}
	}
    return answer;
}
