#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
  for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		if (tmp == n)
		{
			answer++; continue;
		}
		for (int j = i+1; j < n; j++)
		{

			if (tmp + j > n) break;
			tmp += j;
			if (tmp == n)
			{
				answer++; break;
			}
		}
	}
    
    return answer;
}
