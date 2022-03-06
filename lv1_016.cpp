// 프로그래머스 코딩테스트 연습
// LV1 : 콜라츠 추측

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num; // 오버플로 문제로 인해 longlong 타입을 써야 한다.
    int answer = 0;
    while(n != 1 && answer < 500)
    {
        n = (n % 2 == 0 ? n/2 : (n*3)+1);
        answer++;
    }
    return (answer >= 500 ? -1 : answer);
}
