#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 5;
    vector<int> lost = { 4, 2 };
    vector<int> reserve = { 3, 5 };
    vector<int> chk(n + 2, 1);
    // 최대 크기 + 2로 범위 이탈 방지
    // 일단 체육복은 1벌씩 있다고 가정함

    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    // 도난 신고가 꼬여있을 수도 있으니까 일단 번호순으로 정렬하고 처리한다.

    int answer = 0; answer = n;

    for (int i = 0; i < lost.size(); i++) // 털렸는지 기록함
    {
        chk[lost[i]]--;
    }

    for (int i = 0; i < reserve.size(); i++) // 여벌이 있는지 기록함
    {
        chk[reserve[i]]++; // 빌려줄 수 있는 경우 체크
    }


    for (int j = 0; j < lost.size(); j++) // 빌리기 시작
    {
        if (chk[lost[j]] == 0) // 체육복이 없다면
        {
            if (chk[lost[j] - 1] > 1) // 앞사람한테 묻는다
            {
                chk[lost[j] - 1]--; // 빌려줌
            }
            else if (chk[lost[j] + 1] > 1) // 뒷사람한테 묻는다
            {
                chk[lost[j] + 1]--; // 빌려줌
            }
            else // 빌릴 수 없다면
            {
                answer--; // 답에서 하나 뺀다
            }
        }

    }

    cout << answer << '\n';

    return answer;
}