// 프로그래머스 코딩테스트 연습
// LV2 : 메뉴 리뉴얼

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;
vector<int> mx(11, 0);

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for (size_t i = 0; i < orders.size(); i++)
	{
		
		for (size_t j = 0; j < course.size(); j++)
		{
			if (orders[i].length() < course[j]) break;
      // 더 이상 부분문자열을 생성할 수 없는 경우 종료
      // 문자열이 더 긴 경우는 생각하지 않아도 된다 = course 안에 있는 숫자 만큼만 수행되고 course의 크기만큼만 수행된다.
			vector<bool> sel(orders[i].length(), false);
			for (int k = 0; k < course[j]; k++) sel[k] = true; // 이번에 뽑을 양 만큼 true를 추가한다.
      
			sort(sel.begin(), sel.end()); // 정상적인 조합 생성을 위해 정렬한다.
			do
			{
				string tmp = "";
				for (size_t t = 0; t < sel.size(); t++)
				{
					if (sel[t] == true) tmp += orders[i][t];
				}
                
				sort(tmp.begin(), tmp.end());
        // 정상적인 비교를 위해서 문자열도 알파벳 순으로 정렬해준다.
                
        if (mp.find(tmp) != mp.end()) // 만약 맵에 찾는 값이 있다면
				{
					mp.find(tmp)->second++; // 주문된 횟수를 증가시킨다.
				}
				else
				{
					mp.insert({ tmp, 1 }); // 없으면 맵에 새로이 추가한다.
				}
                
				mx[tmp.length()] = max(mx[tmp.length()], mp.find(tmp)->second);
        // 해당 길이의 코스 중에서 가장 많이 주문된 회수를 기록할 벡터
        
			} while (next_permutation(sel.begin(), sel.end())); // 백트래킹 대신 순열조합을 사용한다.
		}
	}

	vector<string> result; // 결과 벡터
	for (auto e : mp)
	{
		if (e.second == mx[e.first.length()] && e.second >= 2) // 2번 이상 주문되고 가장 많이 주문된 코스라면
      result.push_back(e.first); // 결과 벡터에 추가한다.
	}
    return result; // 결과를 반환한다.
}
