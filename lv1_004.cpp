// 프로그래머스 코딩테스트 연습
// LV1 : 신규 아이디 추천

#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
	string tmp = "";

	for (size_t i = 0; i < new_id.length(); i++)
	{
		if (isalnum(new_id[i]))
		{
			tmp += tolower(new_id[i]);
		}
		else if (new_id[i] == '-' || new_id[i] == '_')
		{
			tmp += new_id[i];
		}
		else if (new_id[i] == '.')
		{
			if (tmp.length() == 0) // .이 가장 먼저 나온다면 스킵
			{
				continue;
			}
			else if (tmp[tmp.length() - 1] == '.') // .이 연속해서 나온다면 스킵
			{
				continue;
			}
			else
			{
				tmp += new_id[i];
			}
		}
	}

    if(tmp.empty()) tmp += "a";
    if(tmp.front() == '.') tmp.erase(tmp.begin());
    if(tmp.back() == '.') tmp.pop_back();
    if(tmp.length() >= 16) tmp = tmp.substr(0, 15);
    if(tmp.back() == '.') tmp.pop_back();
    while(tmp.length() <= 2) tmp += tmp.back();
    
	return tmp;
}
