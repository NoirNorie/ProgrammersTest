#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<pair<string, int>> result;
	vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    q.push({begin, 0}); // BFS 시작
    while (q.empty() != true)
	{
		pair<string,int> current = q.front(); q.pop();
        
        if (current.first == target)
		{
			result.push_back(current);
		}
        for (int i = 0; i < words.size(); i++)
		{
			// 방문한 곳은 방문하지 않는다.
			if (visited[i] == true) continue;

			int dif = 0; int pos = 0;
			for (int w = 0; w < current.first.size(); w++)
			{
				if (current.first[w] != words[i][w]) // 다른 부분이 존재한다면
				{
					dif++;
				}
				if (dif > 1) break; // 연산 종료
			}
			// 두 글자 이상 차이나는 경우는 변경할 수 없음
			if (dif > 1) continue;

			q.push({ words[i], current.second + 1 });
			visited[i] = true; // 방문했다고 표시한다.
		}
    }

	if (result.size() == 0)
	{
		answer = 0;
	}
	else
	{
		sort(result.begin(), result.end());
		answer = result[0].second;
	}
    
    return answer;
}
