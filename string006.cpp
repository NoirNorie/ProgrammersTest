#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool chk = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (chk == true && s[i] != ' ')
		{
			s[i] = toupper(s[i]);
			chk = false;
			continue;
		}
		if (s[i] == ' ')
		{
			chk = true;
		}
		else
		{
			s[i] = tolower(s[i]);
		}
			
	}
    
    return s;
}

#include <string>
#include <vector>

using namespace std;
string solution(string s) {
   
  for(int i = 0 ; i < s.length(); i++)
  {
    if(i == 0) s[i] = toupper(s[i]);
    else
    {
      s[i-1] == ' ' ? s[i] = toupper(s[i]) : s[i] = tolower(s[i]);
    }
  }
    return s;
}
