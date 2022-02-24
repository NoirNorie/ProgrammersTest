// 프로그래머스 코딩테스트 연습
// LV1 : 2016년

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED","THU"};
    vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31}; // 잊고 있었는데 7월과 8월은 둘 다 31일이다.
    int daydif = b-1;
    for(int i = 1 ; i < a; i++)
    {
        daydif += month[i-1];
    }
    string answer = day[daydif % 7];
    return answer;
}
