#include <string>
#include <vector>

using namespace std;
int dp[100001];

int solution(int n) {
    int answer = 0;
    
    dp[0] = 0; dp[1] = 1; // 기저 상태 정의
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] % 1234567) + (dp[i-2] % 1234567);
	}

	answer = dp[n] % 1234567;
    
    return answer;
}
