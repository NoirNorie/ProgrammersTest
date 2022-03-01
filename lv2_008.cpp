// 프로그래머스 코딩테스트 연습
// LV2 : 압축

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    map<string, int> dic;
    int idx = 1;
    // 일단 길이 1짜리를 사전에 넣는다.
    for (idx; idx <= 26; idx++)
    {
        char alp = 'A' + idx - 1; 
        dic.insert({string(1,alp), idx });
    }
    vector<int> answer;
    string tmp = "";
    string finder;
    for (size_t i = 0; i < msg.length(); i++)
    {
        tmp = tmp + msg[i]; // 현재 입력
        if (i != msg.length() - 1) finder = tmp + msg[i + 1];
        else // 마지막 남은 값 사출
        {
            answer.push_back(dic.find(tmp)->second);
            break;
        }
        if (dic.find(finder) != dic.end()) // 사전에 존재하는 단어라면
        {
            continue; // 다음 루프를 진행한다.
        }
        else // 존재하지 않으면
        {
            // cout << "사전 추가 " << finder << " " << idx << '\n';
            dic.insert({ finder, idx++ }); // 사전에 추가한다.
            answer.push_back(dic.find(tmp)->second);
            tmp = "";
        }
    }


    return answer;
}
