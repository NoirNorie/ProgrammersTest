#include <string>
#include <vector>
#include <set>
using namespace std;

set<pair<int, int>> st;

// 지우기 위해 조사해봐야 하는 부분
vector<pair<int, int>> srch = { {0,1}, {1,0}, {1,1} };

void sel_square(vector<string>& board, int x, int y)
{
	char c = board[y][x];
	for (int i = 0; i < srch.size(); i++)
	{
		int dx = x + srch[i].second, dy = y + srch[i].first;

		if (dx >= board[0].size() || dy >= board.size()) return; // 범위 이탈 검사
		if (board[dy][dx] != c) return; // 다른 세 부분을 검사하는 중에 다른 부분이 존재한다면 취소
	}
	// 다 통과했다면
	st.insert({ y, x });
	for (int i = 0; i < srch.size(); i++)
	{
		int dx = x + srch[i].second, dy = y + srch[i].first;
		st.insert({ dy, dx }); // 좌표 쌍을 집어넣는다.
	}
}

bool push_down(vector<string>& board)
{
	bool chk = true;
	for(int x = 0; x < board[0].size(); x++)
	{
		for (int y = board.size() - 1; y >= 0; y--)
		{
			if (y == board.size() - 1) continue; // 범위 이탈 방지
			if (board[y][x] != '-' && board[y + 1][x] == '-') // 아래에 삭제된 것이 있다면
			{
				chk = false;
				int dy = y;
				char c = board[y][x];
				while (true)
				{
					board[dy][x] = '-';
					board[dy+1][x] = c; // 둘을 교환한다

					dy++; // 아래를 검사한다
					if (dy+1 >= board.size()) break; // 범위 이탈 시 종료
					if (board[dy+1][x] != '-') break;
				}
			}
		}
	}
	return chk;
}

int solution(int m, int n, vector<string> board) {
    bool not_done = false;
	int answer = 0;
	do
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == '-') continue;				
				else
				{
					sel_square(board, j, i); // 지울 부분을 검사하는 함수
				}
				
			}
		}

		// 블록 제거
		for (auto e : st) board[e.first][e.second] = '-';
		answer += st.size();
		st.clear();

		not_done = push_down(board); // 블록 낙하

	} while (not_done != true);
    return answer;
}
