#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<char> vc = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
int rtn_idx(char ch, vector<int>& lined)
{
	int idx = 0, fnd = 0;

	for (int i = 0; i < 8; i++)
	{
		if (vc[i] == ch)
		{
			fnd = i;
			break;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (lined[i] == fnd)
		{
			idx = i;
			break;
		}
	}
	return idx;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	

		int answer = 0;

	vector<int> lined(8);
	for (int i = 0; i < 8; i++) 
		lined[i] = i;

	do // 모든 경우에 대해 조사한다.
	{
		bool chk = true;

		for (int i = 0; i < data.size(); i++)
		{
			int it1 = rtn_idx(data[i].at(0), lined);
			int it2 = rtn_idx(data[i].at(2), lined);
			char cond = data[i].at(3);
			int dist = data[i].at(4) -'0' + 1; // 거리가 동일한 것이 1부터 시작하므로 1씩 커야 한다.

			if (cond == '=')
			{
				if (abs(it1 - it2) != dist)
				{
					chk = false; break;
				}
			}
			else if (cond == '>')
			{
				if (abs(it1 - it2) <= dist)
				{
					chk = false; break;
				}
			}
			else if (cond == '<')
			{
				if (abs(it1 - it2) >= dist)
				{
					chk = false; break;
				}
			}
		}

		if (chk == true)
		{
			answer++;
		}

	} while (next_permutation(lined.begin(), lined.end()));
    
    
    return answer;
}
