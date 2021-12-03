#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string sfix(string x) // 문자열에 #을 제거하는 과정
{
	string fix_m = "";
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == '#') continue; // #은 이전 반복에서 처리함
    // 뒤의 문자가 #인 경우 합쳐서 소문자로 변환한다(문제에서 소문자를 사용하지 않으므로)
    // 만약 소문자를 사용한다면 QWERTY 이런 식으로 안쓰는 문자로 토큰화 해야한다.
		if (x[i + 1] == '#') fix_m += tolower(x[i]);
		else fix_m += x[i];
	}
	return fix_m;
}

string solution(string m, vector<string> musicinfos) {
  string answer = "(None)";  // 한 번도 정답 문자열에 접근하지 못한다면 그대로 반환해버리면 되도록 지정한다.
	string fix_m = sfix(m); // 들은 멜로디를 변환한다.
	int post_time = 0; // 최장 시간을 체크할 변수

	for (int ls = 0; ls < musicinfos.size(); ls++)
	{
		string sbf; vector<string> tmp; istringstream ss(musicinfos[ls]); // sstream을 이용한 문자열 쪼개기
		while (getline(ss, sbf, ',')) tmp.push_back(sbf); // 벡터의 문자열을 쪼갠다.

		// 시간을 추출한다.
		int ed_hour = stoi(tmp[1].substr(0, 2)), ed_minute = stoi(tmp[1].substr(3));
		int st_hour = stoi(tmp[0].substr(0, 2)), st_minute = stoi(tmp[0].substr(3));
		
		int tm = ed_minute - st_minute, ad = 0;
    // 분을 먼저 구한다
		if (tm < 0) { tm += 60; ad--; } // 분에서 음수가 나온 경우 양수로 바꾸고 시간에서 빼줄 수 있도록 ad를 감소시킨다.
		int th = ed_hour - st_hour + ad; // 시간을 구한다.

		int play_time = (th * 60) + tm; // 재생시간을 분 단위로 변환한다.

		string title = tmp[2]; // 제목
		string listen = tmp[3]; // 들린 멜로디

		string melody = sfix(listen); // 들린 멜로디도 # 부분이 존재할 수 있으므로 처리해준다.

		if (melody.length() < play_time) // 멜로디가 재생 시간보다 짧다면 늘여야 한다.
		{
			int idx = 0;
			while (melody.length() <= play_time) melody += melody[idx++];// 재생 시간 만큼 늘린다.
		}
		else // 멜로디가 재생 시간보다 길다면 자른다 
		{
			melody = melody.substr(0, play_time);
		}

		if (melody.find(fix_m) != string::npos) // 일치하는 문자열이 있다면
		{
			if (play_time > post_time) // 제일 재생시간이 긴 노래를 기록한다(문제 조건)
			{
				answer = title;
				post_time = play_time;
			}
		}
	}
    
    return answer;
}
