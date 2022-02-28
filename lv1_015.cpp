// 프로그래머스 코딩테스트 연습
// LV1 : 최소직사각형

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int w = 0, h = 0;
    for (size_t i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1]) // 돌린다.
        {
            int tmp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = tmp;
        }
    }

    for (size_t i = 0; i < sizes.size(); i++)
    {
        if (w < sizes[i][0]) w = sizes[i][0];
        if (h < sizes[i][1]) h = sizes[i][1];
    }
    return w * h;
}
