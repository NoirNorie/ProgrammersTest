#include <string>
#include <vector>

using namespace std;

int zero = 0;
int one = 0;
vector<vector<int>> area;

void QUAD(int r, int a, int b) // r = 가로 세로 크기, ab = 시작 좌표
{
	if (r == 1) // 더 분해할 수 없다면
	{
		if (area[a][b] == 1) one++;
		else zero++;
	}
	else // 더 분해할 수 있다면
	{
		// 영역 검사
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++)
			{
				if (area[a][b] != area[a+i][b+j]) // 다른 지점이 존재한다면
				{
          // 쿼드 트리이므로 4분할하여 재귀를 시작한다.
					QUAD(r / 2, a, b); 
					QUAD(r / 2, a + r/2, b);
					QUAD(r / 2, a, b + r/2);
					QUAD(r / 2, a + r/2, b + r/2);
					return; // 더 반복하지 않도록 4분할 재귀가 완료되었다면 종료시킨다.
				}
			}
		}
		// 여기에 도달했다면 다른 부분이 없다는 것
		if (area[a][b] == 1) one++;
		else zero++;
	}
}

vector<int> solution(vector<vector<int>> arr) {
    area = arr;
	vector<int> answer;

	QUAD(arr.size(), 0, 0);

	answer.push_back(zero);
	answer.push_back(one);
    
    return answer;
}
