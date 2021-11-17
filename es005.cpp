#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
	// 문자열 검사
	for (int i = 0; i < str1.length(); i++)
	{
		str1[i] = toupper(str1[i]);
	}
	for (int i = 0; i < str2.length(); i++)
	{
		str2[i] = toupper(str2[i]);
	}
    
	// 두개씩 자른다
	vector<string> v1;
	for (int i = 0; i < str1.length() - 1; i++)
	{
		string tmp = str1.substr(i, 2);
		if (!isalpha(tmp[0]) || !isalpha(tmp[1])) continue;
		v1.push_back(tmp);

	}
	vector<string> v2;
	for (int i = 0; i < str2.length() - 1; i++)
	{
		string tmp = str2.substr(i, 2);
		if (!isalpha(tmp[0]) || !isalpha(tmp[1])) continue;
		v2.push_back(tmp);
	}
    
    // 정렬한다
    sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
    
    vector<string> uv(v1.size() + v2.size()); // 합집합 벡터
	vector<string> iv(v1.size() + v2.size()); // 교집합 벡터

    // 집합을 만든다
	auto uv_iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), uv.begin());
	auto iv_iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), iv.begin());
    
    // 남은 공간 제거
    uv.erase(uv_iter, uv.end());
	iv.erase(iv_iter, iv.end());
    

	if (iv.size() == 0 && uv.size() == 0)
	{
		answer = 65536;
	}
	else
	{
		answer = iv.size() * 65536;
		answer /= uv.size();
	}
  
    return (int)answer;
}
