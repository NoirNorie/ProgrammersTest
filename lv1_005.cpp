// 프로그래머스 코딩테스트 연습
// LV1 : 크레인 인형뽑기 게임

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> stk;
	int answer = 0;

	for (size_t i = 0; i < moves.size(); i++)
	{
		for (size_t a = 0; a < board.size(); a++)
		{
			if (board[a][moves[i] - 1] != 0) // 인형이 있다면
			{
				if (stk.empty() != true)
				{
					if (stk.top() == board[a][moves[i] - 1])
					{

						stk.pop();
						answer++; // 제거된 횟수를 증가시킨다.
					}
					else
					{
						stk.push(board[a][moves[i] - 1]);
					}
				}
				else // 스택이 비었다면
				{
					stk.push(board[a][moves[i] - 1]); // 스택에 집어넣는다.
				}

				board[a][moves[i] - 1] = 0; // 인형을 제거한다.
				break; // 인형을 뽑았으므로 넘어간다.
			}
		}
	}
    
    return answer * 2; // 인형은 한 쌍씩 사라진다 = 사라지는 횟수가 아니다.
}
