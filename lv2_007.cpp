// 프로그래머스 코딩테스트 연습
// LV2 : 점프와 순간이동

#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    // 동적 계획법으로 풀었는데 정확도는 문제가 없으나 효율성에서 메모리 초과가 난다.
    //vector<int>dp(n+1, 0);
    //dp[1] = 1; // 기저값 정의
    //for(int i = 2; i <= n; i++)
    //{
    //    if(i%2 == 0) dp[i] = dp[i/2];
    //    else dp[i] = dp[i-1] + 1;
    //}
    //return dp[n];
}

int solution(int n)
{   
    int ans = 0;
    while(n) // 그리디로 풀어야 하는 것인가 보다.
    {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
