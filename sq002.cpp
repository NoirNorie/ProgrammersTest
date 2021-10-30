#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> priorities(N); int location;

	for (int i = 0; i < N; i++)
	{
		cin >> priorities[i];
	}

	cin >> location;

	int answer = 0;
	deque<int> dq(priorities.size());
	for (int i = 0; i < priorities.size(); i++)
	{
		dq[i] = priorities[i];
	}

	while (true)
	{
		int max = 0;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] > max) max = dq[i];
		}

		int r = 0;
		while (r < dq.size())
		{
			if (dq.front() == max)
			{
				dq.pop_front();
				answer++;
				if (location == 0)
				{
					std::cout << answer << '\n';
					return 0;
				}
				else
				{
					location--;
					if (location < 0) location = dq.size() - 1;
				}

				break;
			}
			else
			{
				int tmp = dq.front();
				dq.pop_front(); dq.push_back(tmp);
				location--;
				if (location < 0) location = dq.size() - 1;
			}
			r++;
		}
	}

	
	return 0;
}