#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
   
    int i = 0;
    while (i < progresses.size())
    {
        int f = i;
        int comp = 0; // 오늘 완료된 테스크 수
        // 프로세스를 속도만큼 증가시킨다.
        for (int t = 0; t < progresses.size(); t++)
        {
            progresses[t] += speeds[t];
        }

        for (; f < progresses.size();)
        {
            // 선행 프로세스가 완수되지 않았다면 뒤의 프로세스는 볼 필요 없다.
            if (progresses[f] < 100) 
            {
                break;
            }
            else // 완수 되었다면
            {
                comp++; // 완료된 프로세스 수를 하나 증가시킨다.
                f++; // 다음 프로세스 검사
            }
        }

        if (comp != 0) // 완수된 프로세스가 있다면
        {
            answer.push_back(comp);
            i += comp; // 오늘 완료된 프로세스 만큼 더해준다.
        }
    }
    return answer;
}