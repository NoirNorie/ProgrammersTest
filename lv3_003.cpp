// 프로그래머스 코딩테스트 연습
// LV3: 2 * n 타일링
// 대표적인 DP 문제

#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
	vector<long long> dp(n+1, 0);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
  
	for (long long i = 3; i <= n; i++) dp[i] = (dp[i - 1] % 1000000007) + (dp[i - 2] % 1000000007);
  
	long long answer = 0;
	answer = dp[n] % 1000000007;
  return answer;
}
