#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second; // 재생 수로 정렬함
}

bool cmp_num(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m1; // 장르, 총 재생수를 기록할 맵
    map<string, vector<pair<int, int>>> m2; // 장르, 재생수, 고유번호를 기록할 맵  
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); i++)
    {
        auto it = m1.find(genres[i]);
        if (it == m1.end()) // 못찾음
        {
            m1[genres[i]] = plays[i]; // 총 재생 수 기록
            m2[genres[i]].push_back({ plays[i], i }); // 재생 수, 고유번호를 기록함
        }
        else // 찾음
        {           
            it->second += plays[i]; // 총 재생 수에 재생 수 추가
            m2[genres[i]].push_back({ plays[i], i }); // 재생 수, 고유번호를 기록함
        }
    }
    
    vector<pair<string, int>> vct(m1.begin(), m1.end());
    sort(vct.begin(), vct.end(), cmp);
    
    for (auto e : vct)
    {
        sort(m2[e.first].begin(), m2[e.first].end(), cmp_num);
        for (int i = 0; i < m2[e.first].size(); i++)
        {
            if (i > 1) break;
            answer.push_back(m2[e.first][i].second);
        } 
    }
    
    return answer;
}
