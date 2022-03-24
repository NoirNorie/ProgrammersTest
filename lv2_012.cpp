// 프로그래머스 코딩테스트 연습
// LV2 : 예상 대진표
// 문제는 긴데 논리적으로는 쉽다

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int r = 0;
	do
	{
		if (a % 2 != 0) a++;
		if (b % 2 != 0) b++;
		a /= 2;
		b /= 2;
		r++;
	} while (a != b);
    return r;
}
