#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> vct(n, vector<int>(n, 0));
    int nums = 1; int t;
	int i = 0, j = 0;
	while (n > 0)
	{
		t = 0;
		while (t < n)
		{
			vct[i++][j] = nums++;
			t++;
		}
		n--; i--;

		t = 0;
		while (t < n)
		{
			vct[i][++j] = nums++;
			t++;
		}
		n--;

		t = 0;
		while (t < n)
		{
			vct[--i][--j] = nums++;
			t++;
		}
		i++; n--;
	}

	for (auto e : vct)
	{
		for (auto z : e)
		{
			if (z == 0) continue;
			else answer.push_back(z);
		}
	}
    
    
    return answer;
}
