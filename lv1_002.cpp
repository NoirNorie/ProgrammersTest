// 프로그래머스 코딩테스트 연습
// LV1 : 숫자 문자열과 영단어

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    map<string, int> transmap;
	transmap.insert({ "0", 0 }); transmap.insert({ "zero", 0 });
	transmap.insert({ "1", 1 }); transmap.insert({ "one", 1 });
	transmap.insert({ "2", 2 });   transmap.insert({ "two", 2 });
	transmap.insert({ "3", 3 });   transmap.insert({ "three", 3 });
	transmap.insert({ "4", 4 });   transmap.insert({ "four", 4 });
	transmap.insert({ "5", 5 });   transmap.insert({ "five", 5 });
	transmap.insert({ "six", 6 }); transmap.insert({ "6", 6 });
	transmap.insert({ "7", 7 }); transmap.insert({ "seven", 7 });
	transmap.insert({ "8", 8 });   transmap.insert({ "eight", 8 });
	transmap.insert({ "9", 9 });   transmap.insert({ "nine", 9 });
    
    string con = "", tmp_string = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		con += s[i]; // 문자를 가져온다.
		if (transmap.find(con) != transmap.end()) // 찾는 값이 있다면
		{
			tmp_string += to_string(transmap[con]);
			con = "";
		}
	}
    
    answer = stoi(tmp_string);
    
    
    return answer;
}


#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");    
    return stoi(s);
}

// regex_replace 함수
// regex_replace.(대상 문자열, regex(찾는 문자열), 치환 문자열)
// - #include <regex> 필요
// 찾는 문자열에 지정한 문자열과 일치하는 모든 문자열을 치환하는 함수
