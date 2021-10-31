#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };

	vector<int> answer;

	vector<int>::iterator iter;
	for (int i = 0; i < commands.size(); i++)
	{
		iter = array.begin();
		vector<int> tmp(iter + commands[i][0] - 1, iter + commands[i][1]);

		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < tmp.size(); j++)
		{
			cout << tmp[j] << " ";
		}
		cout << tmp[commands[i][2] - 1] << '\n';
		
		answer.push_back(tmp[commands[i][2] - 1]);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}