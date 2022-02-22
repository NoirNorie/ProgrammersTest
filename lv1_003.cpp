// 프로그래머스 코딩테스트 연습
// LV1 : 신고 결과 

#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    map<string, set<string>> ReportMap;
    map<string, int> MailMap; // 메일 보낼 횟수를 기록할 맵
    vector<int> reportCount;
    string sbuf;

    for (size_t i = 0; i < report.size(); i++)
    {
        istringstream ss(report[i]);
        vector<string> tmp;
        while (getline(ss, sbuf, ' '))
        {
            tmp.push_back(sbuf);
        }
        if (ReportMap.find(tmp[1]) != ReportMap.end()) // 신고된 적이 있다면
        {
            ReportMap.find(tmp[1])->second.insert(tmp[0]);
        }
        else // 신고된 적이 없다면
        {
            set<string> tst;
            tst.insert(tmp[0]);
            ReportMap.insert({ tmp[1], tst });
        }   
    }

    for (size_t i = 0; i < id_list.size(); i++)
    {
        if (ReportMap.find(id_list[i]) != ReportMap.end())
        {
            if (ReportMap.find(id_list[i])->second.size() >= k) // 신고된 횟수가 지정한 값 이상이면
            {
                for (auto e : ReportMap.find(id_list[i])->second)
                {
                    if (MailMap.find(e) != MailMap.end())
                    {
                        MailMap[e]++;
                    }
                    else
                    {
                        MailMap[e] = 1;
                    }
                }
            }

        }
    }
    vector<int> answer;
    for (size_t i = 0; i < id_list.size(); i++)
    {
        if (MailMap.find(id_list[i]) != MailMap.end())
        {
            answer.push_back(MailMap.find(id_list[i])->second);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}
