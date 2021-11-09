#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> wait; //지난 트럭, 건너는 트럭, 대기 트럭의 큐
deque<pair<int, int>> mov;
int main()
{
	int bridge_length = 100; // 차량 수 제한
	int bridge_limits = bridge_length;
	int weight = 100; // 다리 제한 하중
	vector<int> truck_weights = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }; // 진입하는 트럭 벡터

	
	for (auto e : truck_weights) wait.push({ e, 0 }); // 대기 큐에 집어넣는다.
	int t = 0; // 시간
	
	while (1) // 대기하는 트럭이 모두 통과할 때까지 반복한다.
	{
		t++; // 시간 증가
		if (mov.empty() == true && wait.empty() == true) break;
		if (wait.empty() != true) // 대기 차량이 있다
		{
			if (bridge_limits > 0) // 차량 수 제한에 안걸리고
			{
				if (weight - wait.front().first >= 0) // 무게 제한에 안걸리고
				{
					cout << "시간 : " << t << " : " << wait.front().first << "진입" << '\n';
					mov.push_back({wait.front().first, wait.front().second});
					weight -= wait.front().first; // 하중 감소
					wait.pop(); // 차량을 진입시킨다.
					bridge_limits--; // 진입 가능 차량 감소
				}
			}
		}


		// 통과 검사
		if (mov.empty() != true) // 건너는 트럭이 있다면
		{
			for (int i = 0; i < mov.size(); i++)
			{
				mov[i].second++;
				cout << "시간 : " << t << " : 차량 " << 
					mov[i].first << "통과 중 " << "거리 : " << mov[i].second << '\n';
			}

			for (int i = 0; i < mov.size(); i++)
			{
				if (mov.empty() != true)
				{
					if (mov.front().second >= bridge_length)
					{
						cout << "시간 : " << t << " : " << mov.front().first << "통과" << '\n';
						weight += mov.front().first; // 사용한 무게 만큼 반환한다.
						mov.pop_front(); // 차량이 도착했다.
						bridge_limits++; // 진입 가능 차량 수 증가
					}
					else break; // 순서대로 진입하므로 뒷 차들은 생각할 필요 없다
				}
			}

		}
	}

	cout << t<< '\n';

	return 0;
}


// 제출 본

#include <string>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> wt; // 대기 트럭의 큐
    deque<pair<int, int>> mv; // 지난 트럭, 건너는 트럭,
    int bridge_limits = bridge_length;
    int answer = 0;
    
    for (auto e : truck_weights) wt.push({ e, 0 }); // 대기 큐에 집어넣는다.
	int t = 0; // 시간
    
    while (1) // 대기하는 트럭이 모두 통과할 때까지 반복한다.
	{
		t++; // 시간 증가
		if (mv.empty() == true && wt.empty() == true) break;
		if (wt.empty() != true) // 대기 차량이 있다
		{
			if (bridge_limits > 0) // 차량 수 제한에 안걸리고
			{
				if (weight - wt.front().first >= 0) // 무게 제한에 안걸리고
				{
					mv.push_back({wt.front().first, wt.front().second});
					weight -= wt.front().first; // 하중 감소
					wt.pop(); // 차량을 진입시킨다.
					bridge_limits--; // 진입 가능 차량 감소
				}
			}
		}


		// 통과 검사
		if (mv.empty() != true) // 건너는 트럭이 있다면
		{
			for (int i = 0; i < mv.size(); i++)
			{
				mv[i].second++;
			}

			for (int i = 0; i < mv.size(); i++)
			{
				if (mv.empty() != true)
				{
					if (mv.front().second >= bridge_length)
					{
						weight += mv.front().first; // 사용한 무게 만큼 반환한다.
						mv.pop_front(); // 차량이 도착했다.
						bridge_limits++; // 진입 가능 차량 수 증가
					}
					else break; // 순서대로 진입하므로 뒷 차들은 생각할 필요 없다
				}
			}

		}
	}
    answer = t;
    
    
    return answer;
}
