#include <iostream>
#include<vector>
using namespace std;

inline int Minimum(int a, int b, int c)
{
	return ((a > b ? b : a) > (b > c ? c : b) ? (b > c ? c : b) : (a > b ? b : a));
}

int n, m;

int solution(vector<vector<int>> board)
{
    n = board.size();
	m = board[0].size();
	vector<vector<int>> calc(n+1, vector<int>(m+1));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			calc[i + 1][j + 1] = board[i][j];
		}
	}

	int mx = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1 ;j <= m; j++)
		{
			if (calc[i][j] != 0)
			{
				calc[i][j] = Minimum(calc[i - 1][j - 1], calc[i - 1][j], calc[i][j - 1]) + 1;
				if (mx < calc[i][j]) mx = calc[i][j];
			}
			
		}
	}

    return mx * mx;
}
