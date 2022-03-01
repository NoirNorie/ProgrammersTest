// 프로그래머스 코딩테스트 연습
// LV2 : 이진 변환 반복하기

#include <string>
#include <vector>
#include <regex>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    do
    {
        int cnt = 0;
        for (size_t i = 0; i < s.length(); i++) if (s[i] == '0') cnt++;
        s = regex_replace(s, regex("0"), ""); // 0을 제거한다.
        int len = s.length();
        s = "";
        while (len > 0)
        {
            s += to_string(len % 2);
            len /= 2;
        }

        answer[0]++;        // 변환 회수 추가
        answer[1] += cnt;   // 제거한 0의 수 증가
    } while (s.length() != 1);
    return answer;
}
