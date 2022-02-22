// 프로그래머스 코딩테스트 연습
// LV1 : 폰켓몬

#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	set<int> currentSelect(nums.begin(), nums.end());
    if(currentSelect.size() > nums.size() / 2) answer = nums.size()/2;
    else answer = currentSelect.size();
	
    return answer;
}

// 사실 더 짧게도 된다.

int solution(vector<int> nums)
{
	set<int> currentSelect(nums.begin(), nums.end());
  return min(currentSelect.size(), nums.size()/2);
}
