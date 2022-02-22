// 프로그래머스 코딩테스트 연습
// LV1 : 로또의 최고 순위와 최저 순위

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> checkerSet;
    
    for(auto e : win_nums) checkerSet.insert(e);

    int highRank = 1, lowRank = 7, incorrect = 0, correct = 0;
    
    for(size_t i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] != 0)
        {
            if(checkerSet.find(lottos[i]) != checkerSet.end()) correct++;
            else incorrect++;
        }
    }
    highRank += incorrect;
    lowRank -= correct;
    
    // 로또에 7등은 없다
    if(lowRank >= 7) lowRank = 6;
    if(highRank >= 7) highRank = 6;
    
    // 문제 조건에 맞추기 위해서 벡터에 넣어준다.
    answer.push_back(highRank);
    answer.push_back(lowRank);
    
    return answer;
}
