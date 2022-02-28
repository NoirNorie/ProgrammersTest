// 프로그래머스 코딩테스트 연습
// LV2 : n^2 배열 자르기

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    // 만들고 붙이고 자르는 방법으로 시간 초과가 난다.
    long long idx = -1, row =-1, col = 0;
    vector<int> result;
    for (long long i = left; i <= right; i++)
    {
        int row = i/n;
        int col = i%n;
        result.push_back(max(row+1 , col + 1));
    }
    return result;
}

// 행렬의 행과 열을 반복문 하나로 계산하는 방법을 사용하면 편리함
