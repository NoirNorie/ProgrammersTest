// 프로그래머스 코딩테스트 연습
// LV2 : 피로도

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(), dungeons.end());
    int max_visit = 0;
    
    int nums = dungeons.size();
    vector<int> selector(nums);
    do
    {
        int currentK = k;
        int currentVisit = 0;
        for (size_t i = 0; i < nums; i++)
        {
            if (currentK >= dungeons[i][0]) // 현재 피로도가 던전에 진입할 수 있으면
            {
                currentVisit++; // 진입하고
                currentK -= dungeons[i][1]; // 피로도를 깎는다.
            }
            // 진입 못하면 넘긴다.
           
        }
        max_visit = max(currentVisit, max_visit);

    } while (next_permutation(dungeons.begin(), dungeons.end()));
    return max_visit;
}

// 백트래킹으로도 풀 수 있을 것 같다.
