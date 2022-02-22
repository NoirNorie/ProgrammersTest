// 프로그래머스 코딩테스트 연습
// LV1 : 실패율

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(const pair<int, double> a, const pair<int, double> b)
{
	if (a.second > b.second) return true; 
    else if (a.second == b.second) return a.first < b.first;        
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<int, double>> tmp;
    double noclear, st;
    
	sort(stages.begin(), stages.end()); // upper_bound와 lower_bound는 반드시 정렬이 선행되야 한다
 
    for (int i = 1; i <= N; i++)
	{
		noclear = upper_bound(stages.begin(), stages.end(), i) - lower_bound(stages.begin(), stages.end(), i);
		st = upper_bound(stages.begin(), stages.end(), stages[stages.size() - 1]) - lower_bound(stages.begin(), stages.end(), i);
      
        if(noclear == 0) tmp.push_back(make_pair(i, 0));
        // 프로그래머스 테스트 케이스 중에 분모가 0이 되는 경우를 해결해주지 못한다.
        else tmp.push_back(make_pair(i, (noclear / st)));
        
	}   
    
    sort(tmp.begin(), tmp.end(), cmp);
    
    vector<int> answer;
    for (auto e : tmp) answer.push_back(e.first);

    return answer;
}
