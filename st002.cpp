#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    for (auto e : numbers)
    {
        s.push_back(to_string(e));
    }
    
    sort(s.begin(), s.end(), cmp);
    
    for (auto e : s)
    {
        if (answer == "0" && e == "0") continue;
        answer += e;
    }
    
    return answer;
}
