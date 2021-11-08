#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

stack<string> st;
vector<vector<string>> tk;
int nums;

bool func(int n, string dest, vector<bool>& visited)
{
	if (n == nums - 1) // 길이에 도달
	{
		bool flag = false;
		for (int i = 0; i < tk.size(); i++)
		{
			if (visited[i] == true) continue;
			if (dest == tk[i][0])
			{
				visited[i] = true;
				st.push(tk[i][1]);
				st.push(tk[i][0]);
				return true;
			}
		}	
	}
	else // 아직 길이에 도달하지 못한 경우
	{
		bool flag = false;

		for (int i = 0; i < tk.size(); i++)
		{
			if (visited[i] == true) continue;
			if (dest == tk[i][0])
			{
				int flag = true;
				visited[i] = true;
				if (func(n + 1, tk[i][1], visited))
				{
					st.push(tk[i][0]);
					return true;
				}
				else
				{
					visited[i] = false;
				}
			}
		}
		if (flag == false) // 다음 값이 없다면
			return false;

	}
}

vector<string> solution(vector<vector<string>> tickets) 
{
  vector<string> answer;
  tk = tickets;
  nums = tk.size();
  sort(tk.begin(), tk.end());

	vector<bool> visited(tk.size(), false);

	for (int i = 0; i < tk.size(); i++)
	{
		if (tk[i][0] == "ICN") // 가장 처음 나온 ICN을 찾는다.
		{
			visited[i] = true;
			if (func(1, tk[i][1], visited) == false) // 경로가 없는 경우
			{
				visited[i] = false;
				continue;
			}
			else // 경로가 존재해서 재귀를 하고 오는 경우
			{
				st.push("ICN");
			}	
			break;
		}
	}
    
  while (st.empty() != true)
	{
		answer.push_back(st.top());
		st.pop();
	}
    
    
    return answer;
}
