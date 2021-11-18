#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	return a.size() <= b.size();
}

vector<int> solution(string s) {
    
    vector<vector<int>> vct; // 집합 벡터
	
	string num = "";
	vector<int> tmp; // 임시 벡터
	// 처음과 끝의 대괄호를 무시하는 범위를 설정한다.
	for (int i = 1; i < s.length() - 1; i++) 
	{
		if (s[i] == '{')
		{
			tmp.clear(); // 임시 벡터를 비운다.
		}
		else if (isdigit(s[i])) // 숫자를 만났다면
		{
			num += s[i];
		}
		else if (s[i] == ',') // 쉼표를 만난 경우
		{
			if (s[i - 1] == '}') // 임시 벡터를 집합 벡터에 삽입함
			{
				tmp.push_back(stoi(num));
				vct.push_back(tmp);
				num = "";
			}
			else // 숫자였다면
			{
				tmp.push_back(stoi(num)); // 숫자를 임시 벡터에 삽입함
				num = "";
			}
		}
	}
	// 남은 값들을 모두 집합 벡터에 삽입한다.
	tmp.push_back(stoi(num));
	vct.push_back(tmp);

	sort(vct.begin(), vct.end(), cmp);
    
    vector<int> answer;
	for (int i = 0; i < vct.size(); i++)
	{
		for (int j = 0; j < vct[i].size(); j++)
		{
            if(answer.empty() == true)
            {
                answer.push_back(vct[i][j]);
            }
            else
            {
                bool chk = false;
                for(int t = 0; t < answer.size(); t++)
                {
                    if(answer[t] == vct[i][j])
                    {
                        chk = true;
                        break;
                    }
                }
                if(chk == false) answer.push_back(vct[i][j]);
            }
		}
        cout << '\n';
	}
    
    return answer;
}
