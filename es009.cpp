#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int MAX3(int a, int b, int c)
{
	return ((a > b ? a : b) > (a > c ? a : c) ? (a > b ? a : b) : (a > c ? a : c));
}

int solution(vector<vector<int> > land)
{
	vector<int> result;

	for (size_t i = 0; i < land.size()- 1; i++)
	{
		land[i + 1][0] += MAX3(land[i][1], land[i][2], land[i][3]);
		land[i + 1][1] += MAX3(land[i][0], land[i][2], land[i][3]);
		land[i + 1][2] += MAX3(land[i][0], land[i][1], land[i][3]);
		land[i + 1][3] += MAX3(land[i][0], land[i][1], land[i][2]);
	}

	int answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end()); // 최대 원소 반환

    return answer;
}
