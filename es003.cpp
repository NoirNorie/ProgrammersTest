#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1 ; i <= brown ; i++) // i는 세로 값
    {
        if((i-2) * (((brown + yellow)/i) - 2) == yellow)
        {
            answer.push_back((brown+yellow)/i);
            answer.push_back(i);
            break;
        }
    }    
    return answer;
}
