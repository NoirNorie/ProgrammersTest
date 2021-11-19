#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s)
{
    vector<int> v;
    string buf;
    istringstream ss(s);
    while(getline(ss, buf, ' '))
    {
       v.push_back(stoi(buf));
    }
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    
    string answer = "";
    answer += to_string(mn);
    answer += " ";
    answer += to_string(mx);
      
    return answer;
}
