#include <vector>
#include <queue>
using namespace std;

int a; int b;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    int a = m; int b = n;

	int maxi = 0; // 가장 큰 영역을 기록할 변수
	int area_cnt = 0; // 영역 갯수를 셀 변수

	// 상 하 좌 우로 움직일 때 사용할 배열
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	// BFS에 사용할 큐
	queue<pair<int, int>> q;
    
	vector<vector<bool>> visited(a, vector<bool>(b, false)); // 방문 여부를 기록할 벡터를 생성한다.
    
    for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) // 좌측 상단부터 시작한다.
		{
			if (picture[i][j] == 0) continue; // 0이면 건너뛴다.
			else if (visited[i][j] == true) continue; // 방문한 적 있으면 건너뛴다.
			else // 방문한 적 없고 새 영역을 발견했다면
			{
				int area = picture[i][j]; // 같은 영역을 찾아낼 변수
				int area_size = 1; // 현재 지점의 크기
		
				visited[i][j] = true; // 방문했다고 기록한다.
				q.push({ i, j }); // BFS 시작
				while (q.empty() != true)
				{
					// 현재 좌표
					int cx = q.front().first, cy = q.front().second;
					q.pop(); // 큐에서 제거한다.

					for (int k = 0; k < 4; k++)
					{
						int nx = cx + dx[k], ny = cy + dy[k];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 영역 이탈 방지
						if (visited[nx][ny] == true) continue; // 방문했던 영역이면 건너뛴다
						if (picture[nx][ny] != area) continue; // 다른 영역이어도 건너뛴다.
						// 모든 조건을 만족한다면
						q.push({ nx, ny }); // 큐에 집어넣는다
						visited[nx][ny] = true; // 방문했다고 표시한다.
						area_size++; // 영역 크기 증가
					}
				}
				area_cnt++; // BFS가 종료되었으면 해당 영역을 다 체크한 것이므로 증가시킨다.

				if (area_size > maxi) maxi = area_size; // 가장 큰 영역 비교		
			}
		}
	}  
    
    vector<int> answer(2);
    answer[0] = area_cnt;
    answer[1] = maxi;
    return answer;
}
