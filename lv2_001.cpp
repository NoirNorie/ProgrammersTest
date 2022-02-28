# 프로그래머스 코딩테스트 연습
# Level 2: 멀쩡한 사각형

#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
    long long c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long wid = w; long long hei = h;
    long long answer = wid * hei;
    long long cross = wid + hei - gcd(wid, hei);
    answer -= cross;
    return answer;
}
