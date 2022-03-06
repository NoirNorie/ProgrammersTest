// 프로그래머스 코딩테스트 연습
// LV1 : 평균 구하기

#include <string>
#include <vector>
#include <numeric>
using namespace std;

double solution(vector<int> arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0);
    return sum / arr.size();
}
