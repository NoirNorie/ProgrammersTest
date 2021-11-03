#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
	int answer = 1; // 모든 조합을 담을 변수
	
  vector<pair<string, int>> calc; // 순서쌍을 만들 벡터
	calc.push_back(make_pair(clothes[0][1], 1)); // 처음 타입의 의상을 추가한다.

	for (int i = 1; i < clothes.size(); i++) // 최초 경우는 포함하였으므로 1부터 시작
	{
		string tp = clothes[i][1]; // 옷의 종류, 같은 이름의 옷은 없다는 조건이 있으므로 이름은 생략한다.
		bool same = false;
		for (int j = 0; j < calc.size(); j++) // 같은 타입의 의상이 있는지 검사한다.
		{
			if (tp == calc[j].first) // 같은 종류의 의상이라면
			{
				calc[j].second++; // 의상 수를 추가한다.
				same = true; // 같은 종류라고 표시한다.
				break; // 연산 종료
			}
		}
		
		if (same == false) // 같은 종류의 의상이 아니라면
		{
			calc.push_back(make_pair(tp, 1));
		}
	}

	for (int i = 0; i < calc.size(); i++) 
	{
		answer *= (calc[i].second + 1); // 벗는 경우도 포함하므로 + 1
	}
	answer -= 1; // 다 벗는 경우를 제외해야 하므로 -1
  return answer;
}
