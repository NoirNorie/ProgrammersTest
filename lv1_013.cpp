// 프로그래머스 코딩테스트 연습
// LV1 : 두 개 뽑아서 더하기

#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> tmp;
    sort(numbers.begin(), numbers.end());
    
    for(size_t i = 0; i < numbers.size(); i++)
    {
        for(size_t j = i+1 ; j < numbers.size(); j++)
        {
            tmp.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(tmp.begin(), tmp.end());
    return answer;
}
