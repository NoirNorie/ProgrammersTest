#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a1 = 0, a2 = 0, a3 = 0;
    int i1 = 0, i2 = 0, i3 = 0;
    vector<int> n1 = {1,2,3,4,5};    
    vector<int> n2 = {2,1,2,3,2,4,2,5};
    vector<int> n3 = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == n1[i1++]) a1++;
        if(answers[i] == n2[i2++]) a2++;
        if(answers[i] == n3[i3++]) a3++;
        if(i1 > 4) i1 = 0;
        if(i2 > 7) i2 = 0;
        if(i3 > 9) i3 = 0;
    }
    
    vector<int> tmp = {a1, a2, a3};
    int max = *max_element(tmp.begin(), tmp.end());
    for(int i = 0; i < 3; i++)
    {
        if(max == tmp[i])
            answer.push_back(i+1);
    }
     
    return answer;
}
