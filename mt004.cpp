#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    	string binanry_n = bitset<100>(n).to_string();
	int cnt_n = 0;
	for (int i = 0; i < binanry_n.length(); i++)
	{
		if (binanry_n[i] == '1') cnt_n++;
	} // 1의 개수를 세놓는다.

	int t = n;
	while (true)
	{
		t++;
		string binary_nb = bitset<100>(t).to_string();
		int tmp_n = 0;
		for (int i = 0; i < binary_nb.length(); i++)
		{
			if (binary_nb[i] == '1') tmp_n++;
		}

		if (tmp_n == cnt_n)
		{
			answer = t;
			break;
    }
	}  
    return answer;
}

#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {    
    int num = bitset<100>(n).count();
    
    while((bitset<100>(++n).count()) != num);
      
    return n;
}
