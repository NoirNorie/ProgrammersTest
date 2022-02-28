# 프로그래머스 코딩테스트 연습
# Level 2: K진수에서 소수 개수 구하기

#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(long long n)
{
    if (n < 2) return false;
    for (long long i = 2; i <= sqrt(n); i++) // 다 풀어놓고 <= 를 < 라고 적어서 틀렸다.
    {
        if (n % i == 0) return false;
    }
    return true;
}


int solution(int n, int k) {
    string s = "";

    // 진수 변환
    while (n > 0)
    {
        s += to_string(n % k);
        n /= k;
    }
    string num = string(s.rbegin(), s.rend());
    
    string tmp = ""; int answer = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '0' && !tmp.empty())
        {
            long long n = stoll(tmp);
            if(isPrime(n)) answer++;
            tmp = "";
        }
        else tmp += num[i];
    }
    if (!tmp.empty())
    {
        long long n = stoll(tmp);
        if(isPrime(n)) answer++;
    }
   
    return answer;
}
