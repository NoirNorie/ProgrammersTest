#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++)
	{
		string chk = skill_trees[i];
		bool b = false;

		for (int t = 1; t < skill.length(); t++)
		{
			int post = chk.find(skill[t - 1]);
			int current = chk.find(skill[t]);
			
			if (post > current)
			{
				if (current == -1) continue; // 일단 넘겨본다.
				b = true;
				break;
			}
			else if (post == -1 && current != -1)
			{
				b = true; break;
			}
		}
		if (!b)
		{
			answer++;
		}
	}

    return answer;
}
