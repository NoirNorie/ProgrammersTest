// 프로그래머스 코딩테스트 연습
// LV1 : x만큼 간격이 있는 n개의 숫자

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i = 1 ; i <= n; i++) answer.push_back(x*i);
    return answer;
}
