// 프로그래머스 코딩테스트 연습
// LV2 : 방문 길이

#include <iostream>
#include <string>
#include <set>
using namespace std;

set<pair<pair<int, int>, pair<int, int>>> moveset;

int solution(string dirs) {
    int x = 0, y = 0;
    int cnt = 0;
    for (size_t i = 0; i < dirs.length(); i++)
    {
        // 좌표 이동
        char mv = dirs[i];
        int mvx = 0, mvy = 0;
        if (mv == 'R') mvx++;
        else if (mv == 'L') mvx--;
        else if (mv == 'U') mvy--;
        else mvy++;

        // 범위 이탈시 다음 연산은 무시한다.
        if (x + mvx < -5 || x + mvx > 5) continue;
        if (y + mvy < -5 || y + mvy > 5) continue;

        // 다음 좌표
        int nx = x + mvx, ny = y + mvy;

        if (x < nx || y < ny)
        {
            if (moveset.find({ {x, y}, {nx, ny} }) == moveset.end())
            {
                moveset.insert({ {x,y}, {nx, ny} });
                cnt++;
            }
        }
        else
        {
            if (moveset.find({  {nx, ny},{x, y} }) == moveset.end())
            {
                moveset.insert({ {nx, ny}, {x, y} });
                cnt++;
            }
        }
        x = nx, y = ny;
    }
    return cnt;
}
