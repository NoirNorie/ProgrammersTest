// 프로그래머스 코딩테스트 연습
// LV1 : 핸드폰 번호 가리기

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    for(size_t i = 0 ; i < phone_number.length()-4;i++) phone_number[i] = '*';
    return phone_number;
}
