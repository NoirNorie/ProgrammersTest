#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) // 최대 공약수 구하기
{
	int tmp, n;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int solution(vector<int> arr) {
    int answer = 0;
    int base = arr[0]; // 기저 값
    for(int i = 1 ; i < arr.size(); i++)
    {
        base = (base*arr[i]) / gcd(base, arr[i]);       
    }    
    answer = base;
       
    return answer;
}
