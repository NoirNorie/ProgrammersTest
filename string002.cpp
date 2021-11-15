#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

map<string, string> uid_to_nickname;
vector<pair<int, string>> vis; // 명령(0 : 입장, 1 : 나가기, 2 : 변경), uid 를 기록할 벡터

void cmd_enter(string uid, string current_name)
{
	if (uid_to_nickname.find(uid) != uid_to_nickname.end()) // uid가 기록에 있다면
	{
		uid_to_nickname[uid] = current_name;
	}
	else // 처음 들어온 경우
	{
		uid_to_nickname[uid] = current_name;
	}
}
void cmd_change(string uid, string current_name) // 닉네임 변경
{
	uid_to_nickname[uid] = current_name;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;

	for (int i = 0; i < record.size(); i++)
	{
		string buf;
		vector<string> cmd;
		istringstream ss(record[i]);
		while (getline(ss, buf, ' ')) 
			cmd.push_back(buf);

		if (cmd[0] == "Enter") // 입장
		{
			cmd_enter(cmd[1], cmd[2]);
			vis.push_back({ 0, cmd[1]}); // 입장, uid를 벡터에 기록한다.
		}
		else if (cmd[0] == "Leave") // 나가기
		{
			vis.push_back({ 2, cmd[1] });
		}
		else // 변경
		{
			cmd_change(cmd[1], cmd[2]);
		}	
	}

	for (int i = 0; i < vis.size(); i++)
	{
		string tmp = "";
		auto it = uid_to_nickname.find(vis[i].second);
		switch (vis[i].first)
		{
		case 0:
			tmp += it->second;
			tmp += "님이 들어왔습니다.";
			break;
		case 2:
			tmp += it->second;
			tmp += "님이 나갔습니다.";
			break;
		}
		answer.push_back(tmp);
	}
    return answer;
}
