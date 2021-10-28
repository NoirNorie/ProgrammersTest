#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    // 둘 다 정렬한다.
    
    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            return answer = participant[i];
            // 다른 지점이 나온다면 그 사람이 완주 못한 사람
        }
    }
    // 마지막까지 다 동일하다면
    answer = participant[completion.size()]; // 마지막 남은 사람이 완주 못한 사람
    return answer;
}