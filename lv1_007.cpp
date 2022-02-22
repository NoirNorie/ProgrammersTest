// 프로그래머스 코딩테스트 연습
// LV1 : 음양 더하기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
	for (size_t i = 0; i < absolutes.size(); i++)
	{
		if (signs[i] == true) answer += absolutes[i];
		else answer -= absolutes[i];
	}
    
    return answer;
}
