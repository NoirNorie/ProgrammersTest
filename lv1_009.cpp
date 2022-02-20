#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {   
    string answer = "";
    // 키패드 줄, 위치 순서쌍 (1,2,3,4)로만 구분한다.
	pair<int, int> rc = make_pair(3, 4);
	pair<int, int> lc = make_pair(1, 4);
	pair<int, int> dt;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			// 왼손 고정
			answer += "L";
			lc.first = 1; lc.second = (numbers[i] / 3 + 1);
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			// 오른손 고정
			answer += "R";
			rc.first = 3; rc.second = (numbers[i] / 3);
		}
		else // 선택의 순간
		{
			if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8)
			{
				dt = { 2, numbers[i]/3 + 1}; // 누를 곳
			}
			else // 0인 경우
			{
				dt = { 2, 4 };
			}
			// 두 지점 간의 거리를 잰다
			int left_dist = abs(lc.first - dt.first) + abs(lc.second - dt.second);
			int right_dist = abs(rc.first - dt.first) + abs(rc.second - dt.second);
						
			if (left_dist < right_dist)
			{
				answer += "L";
				lc.first = 2; lc.second = dt.second;

			}
			else if (left_dist > right_dist)
			{
				answer += "R";
				rc.first = 2; rc.second = dt.second;
			}
			else // 두 지점 간의 거리가 동일하다면
			{
				// 주로 쓰는 손에 따라 결정된다.
				if (hand == "right")
				{
					answer += "R";
					rc.first = 2; rc.second = dt.second;
				}
				else
				{
					answer += "L";
					lc.first = 2; lc.second = dt.second;
				}
			}

		}
	}
    
    return answer;
}
