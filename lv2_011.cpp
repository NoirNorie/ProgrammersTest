// 프로그래머스 코딩테스트 연습
// LV2 : 모음 사전

// 백트래킹으로 중복 조합 구성
// STL의 set 반복자를 이용하여 답을 구함

#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<string> st;
vector<char> vct = { 'A', 'E', 'I','O','U' }; // 모음 모음
int len = 1;

// 백트래킹
void btrk(string s)
{
    // 정해진 길이에 도달한 경우
    if (s.length() == len)
    {
        st.insert(s); // 세트에 삽입함
        return;
    }
    // 길이에 도달하지 못한 경우
    for (size_t i = 0; i < vct.size(); i++)
    {
        s += vct[i];
        btrk(s);
        s = s.substr(0, s.length() - 1); // 맨 마지막 글자 제거
    }
}

int solution(string word) {
    int answer = 0;
    
    for (int i = 0; i < 5; i++)
    {
        btrk("");
        len++;
    }
    
    set<string>::iterator stiter = st.find(word);  
    if (stiter != st.end()) // 찾는 값이 있다면
    {
        iterator_traits<set<string>::iterator>::difference_type n = distance(st.begin(), stiter);
        answer = n+1;
    }
    
    return answer;
}
