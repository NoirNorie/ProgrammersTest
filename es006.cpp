#include <string>
#include <vector>

using namespace std;

// 거리 1을 조사할 배열 (상 하 좌 우에 존재할 시 파티션의 의미가 없음)
int dist1_x[4] = { 1,0,-1,0 };
int dist1_y[4] = { 0,1,0,-1 };
// 거리 2 중에서 대각선 상의 위치를 조사할 배열
int dist2_xt[4] = { 1,-1,-1,1 };
int dist2_yt[4] = { 1,1,-1,-1 };
// 거리 2 중에서 직선 상의 위치를 조사할 배열
int dist2_x[4] = { 2,0,-2,0 };
int dist2_y[4] = { 0,2,0,-2 };

vector<int> solution(vector<vector<string>> places) {
    	vector<int> answer;
	for (int room = 0; room < 5; room++) // 방 5개 순회
	{
		bool current_room = true;
		for (int i = 0; i < 5; i++) // 방의 세로
		{
			for (int j = 0; j < 5; j++) // 방의 가로
			{
				if (places[room][i][j] == 'P') // 현재 좌표에 사람이 앉아 있다면
				{
					int cx = j; int cy = i; // 현재 좌표

					for (int a = 0; a < 4; a++) // 거리 1 조사
					{
						int dx = cx + dist1_x[a]; 
						int dy = cy + dist1_y[a];
						if (dx < 0 || dx >= 5 || dy < 0 || dy >= 5) continue; // 범위 이탈 검사
						if (places[room][dy][dx] == 'P') // 추가 검사가 불필요함
						{
							current_room = false;
							break;
						}
					}
					for (int a = 0; a < 4; a++) // 거리 2 대각 조사
					{
						int dx = cx + dist2_xt[a];
						int dy = cy + dist2_yt[a];
						if (dx < 0 || dx >= 5 || dy < 0 || dy >= 5) continue; // 범위 이탈 검사
						if (places[room][dy][dx] == 'P') // 추가 검사가 필요함
						{
							if (places[room][dy][cx] == 'X' && places[room][cy][dx] == 'X') continue;
							else 
							{
								current_room = false;
								break;
							}
						}

					}
					for (int a = 0; a < 4; a++) // 거리 2 조사
					{
						int dx = cx + dist2_x[a];
						int dy = cy + dist2_y[a];
						if (dx < 0 || dx >= 5 || dy < 0 || dy >= 5) continue; // 범위 이탈 검사
						if (places[room][dy][dx] == 'P') // 추가 검사가 필요함
						{
							if (dx == cx) // 상 하 검사
							{
								if (places[room][(dy + cy) / 2][dx] == 'X') continue;
								else
								{
									current_room = false;
									break;
								}
							}
							else // 좌 우 검사
							{
								if (places[room][dy][(dx + cx) / 2] == 'X') continue;
								else
								{
									current_room = false;
									break;
								}
							}
						}
					}

				}
			}
		}
		if (current_room == true) answer.push_back(1);
		else answer.push_back(0);
	}
    return answer;
}
