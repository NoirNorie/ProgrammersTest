#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool stringCmp(string a, string b)
{
	string HEAD_A = "", NUM_A = "";
	string HEAD_B = "", NUM_B = "";
	int i = 0, j = 0;

	// 앞을 떼어낸다.
	while (!isdigit(a[i]))
	{
		HEAD_A += tolower(a[i]); i++;
	}
	while (!isdigit(b[j]))
	{
		HEAD_B += tolower(b[j]); j++;
	}
	// 숫자를 떼어낸다.
	while (isdigit(a[i]))
	{
		NUM_A += a[i]; i++;
	}
	while (isdigit(b[j]))
	{
		NUM_B += b[j]; j++;
	}

	if (HEAD_A < HEAD_B)
	{
		return true;
	}
	else if(HEAD_A > HEAD_B)
	{
		return false;
	}
	else
	{
		if (stoi(NUM_A) < stoi(NUM_B))
		{
			return true;
		}
		else if (stoi(NUM_A) > stoi(NUM_B))
		{
			return false;
		}
	}	
}

vector<string> solution(vector<string> files) 
{
    stable_sort(files.begin(), files.end(), stringCmp);
    return files;
}
