// 프로그래머스 코딩테스트 연습
// LV3: 정수 삼각형

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
vector<vector<int>> dp(501, vector<int>(501, 0));
    dp[0][0] = triangle[0][0]; // 기저상태
    for (size_t i = 1; i < triangle.size(); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (j == 0) dp[i][j] += triangle[i][j] + dp[i - 1][j];
            else dp[i][j] += triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    int answer = 0;
    int n = triangle.size() - 1;
    for (int i = 0; i < triangle[n].size(); i++)
    {
        answer = max(answer, dp[n][i]);
    }

    return answer;
}
