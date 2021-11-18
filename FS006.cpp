#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 큐
queue<pair<int, int>> qe;

// 상하좌우로 움직일 배열
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int solution(vector<vector<int> > maps)
{
	vector<vector<int>> area = maps;
  // 처음에 다른 방법으로 시도해서 map의 내용을 옮겼는데 이럴 필요 없었다.
  // 그냥 maps로 해도 된다.
    
	int n = area.size(); int m = area[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false)); // 방문 여부를 기록할 벡터

	qe.push({ 0,0 });
	area[0][0] = 1;
	visited[0][0] = true; // BFS 시작 
	while (qe.empty() != true)
	{
		int cy = qe.front().first;
		int cx = qe.front().second;

		if (cx == m - 1 && cy == n - 1) break;
		// 어떤 경우든 맵의 마지막에 가장 먼저 도착했다면 가장 빠른것이므로 더 연산하지 않고 정지시킨다.

		qe.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i]; int nx = cx + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx] == true || area[ny][nx] == 0) continue;

			visited[ny][nx] = true; // 방문했다고 표시한다.
			area[ny][nx] = area[cy][cx] + 1;
				//min(area[ny][nx], area[cy][cx] + 1);
			qe.push({ ny, nx });
		}
	}
	int answer = 0;
	if (area[n - 1][m - 1] == 1) // 도달하지 못했다면 1로 남았을 것이므로
	{
		answer = -1;
	}
	else
	{
		answer = area[n - 1][m - 1];
	}
    return answer;
}
