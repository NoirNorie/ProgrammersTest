#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for(int i = 0 ; i < s.length(); i++)
    {
        if(stk.empty() == true)
        {
            if(s[i] == ')') return false;
            else stk.push(s[i]);
        }
        else
        {
            if(stk.top() == '(')
            {
                if(s[i] == ')') stk.pop();
                else stk.push(s[i]);
            }
            
        }
    }
    
    if(stk.empty() != true) return false;

    return true;
}
