#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<bool> visited(201, false); // 방문 여부를 표시할 벡터
queue<int> q; // 큐

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++)
	{
		if (visited[i] == false) // 방문한적 없는 컴퓨터라면
		{
			visited[i] = true; // 방문한다
			q.push(i); // 큐에 집어넣는다
			while (q.empty() != true) // BFS를 실행한다.
			{
				int current = q.front(); q.pop();
				for (int j = 0; j < n; j++)
				{
					if (j == i) continue; // 자기 자신은 제외한다.
					if (computers[current][j] == 0 || visited[j] == true)  continue;

					// 네트워크가 연결된 컴퓨터라면
					visited[j] = true; // 방문했다고 표시한다.
					q.push(j); // 큐에 집어 넣는다.
				}
			}
			answer++;
		}
	}
    
    return answer;
}
