// 프로그래머스 코딩테스트 연습
// LV1 : 예산

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int tmp = 0;
    sort(d.begin(), d.end()); // 정렬한다.
    while(true)
    {
        if(budget - d[tmp] < 0) break;
        else if(budget -d[tmp] == 0)
        {
            answer++; break;
        }
        else
        {
            answer++;
            budget -= d[tmp++];
        }

        if(tmp == d.size()) break;
    }
    return answer;
}
