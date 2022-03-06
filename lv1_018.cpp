// 프로그래머스 코딩테스트 연습
// LV1 : 하샤드 수

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool solution(int x) {
    int i = 5, sum = 0, t = x;
    while(1) if(x / (int)pow(10,--i) != 0) break;
    while(x > 0)
    {
        sum += x / (int)pow(10, i);
        x = x% (int)pow(10,i--);
    }
    if(sum != 0 && t % sum == 0) return true;
    else return false;
}
