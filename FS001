#include <string>
#include <vector>

using namespace std;

int t;
int answer = 0;

void func(vector<int> numbers, int sum, int r)
{
	if (r == numbers.size()) // 마지막 연산까지 수행했다면
	{
		if (sum == t) answer++;
		return;
	}
	func(numbers, sum + numbers[r], r + 1);
	func(numbers, sum + (numbers[r] * -1), r + 1);
}

int solution(vector<int> numbers, int target) 
{
    t = target;
    func(numbers, 0, 0);
    
    return answer;
}
