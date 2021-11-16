#include <deque>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
  string answer = "";
  deque<int> dq;
  while (n)
	{
		if (n % 3 == 0) // 진법 계산과 차이나는 부분
		{
			dq.push_front(4); // 3으로 나눠지는 경우 4로 치환한다
			n /= 3; // 3으로 나눠준다
			n--; // 몫에서 1을 빼줘야 문제 조건에 부합함
		}
		else // 그 밖의 경우는 진법 계산과 동일함
		{
			dq.push_front(n % 3);
			n /= 3;
		}
	}
    
    for(auto e: dq)
        answer += to_string(e); // 차례대로 내보낸다
    
    return answer;
}
