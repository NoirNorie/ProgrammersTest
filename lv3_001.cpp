// 프로그래머스 코딩테스트 연습
// LV3: N-Queen

#include <string>
#include <vector>

using namespace std;

int x;
int cnt = 0;

bool isused1[40];
bool isused2[40];
bool isused3[40];

void btrk(int current)
{
	if (current == x)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < x; i++)
	{
		if (isused1[i] || isused2[i+current] || isused3[current - i +(x-1)]) continue;

		isused1[i] = true;
		isused2[i+current] = true;
		isused3[current - i +(x-1)] = true;
		btrk(current + 1);
		isused1[i] = false;
		isused2[i + current] = false;
		isused3[current - i + (x-1)] = false;
	}

}

int solution(int n) {
    
    x =n;
    btrk(0);
    return cnt;
}
