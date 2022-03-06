// 프로그래머스 코딩테스트 연습
// LV1 : 행렬의 덧셈

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    for(size_t i = 0 ; i < arr1.size(); i++) for(size_t j = 0 ; j < arr1[i].size(); j++) arr1[i][j] += arr2[i][j];
    return arr1;
}
