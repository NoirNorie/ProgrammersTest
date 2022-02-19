#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers) {
    //int answer = 0;
	//set<int> st(numbers.begin(), numbers.end());
	//for (int i = 0; i < 10; i++)
	//{
	//	if (st.find(i) == st.end()) answer += i;
	//}
    //return answer;
    return 45 - accumulate(numbers.begin(), numbers.end(), 0); // 누산 함수
    

}

// 누산 함수 원형
  template< class InputIt, class T >
  constexpr T accumulate( InputIt first, InputIt last, T init );
-> long long 타입을 쓸 경우 0가 아닌 0LL을 써야 한다.
