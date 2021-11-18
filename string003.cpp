#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<char> ep = { '*', '+', '-' };

long long solution(string expression) {
    long long answer = 0;
    
    string m = expression;
    vector<long long> v;
	vector<char> exp;
	string tmp = "";

	for (int i = 0; i < m.length(); i++)
	{		
		if (isdigit(m[i])) tmp += m[i];
		else if (m[i] == '*' || m[i] == '-' || m[i] == '+')
		{
			v.push_back(stoi(tmp));
			tmp = "";
			exp.push_back(m[i]);
		}
	}
	v.push_back(stoi(tmp));
    
    do
	{
		string t = "";
		for (int i = 0; i < ep.size(); i++) t += ep[i]; // 이번 차례의 연산자 우선 순위 생성
		vector<long long> v2 = v; // 이번에 사용할 숫자 벡터 -> 이 부분에서 걸렸다(가능한 결과가 2^63 - 1 까지 나오므로 long long 이상의 타입으로 연산해야 한다)
		vector<char> exp2 = exp; // 이번에 사용할 연산자 벡터

		for (int i = 0; i < t.length(); i++) // 3개의 연산자 우선 순위에 따라 진행
		{
			int j = 0;
			for (j; j < exp2.size(); j++) // 연산자 벡터에 존재하는 연산자의 개수만큼 반복
			{
				if (exp2[j] == ep[i]) // 연산자가 같다면
				{
					switch (ep[i]) // 그 연산자에 따라 동작을 수행한다.
					{
					case '*':
						v2[j] = v2[j] * v2[j + 1];
						v2.erase(v2.begin() + j + 1); // 스택을 사용하면 더 복잡할 것 같아서 원소를 연산하고 결과만 남기고 나머지는 삭제함
						exp2.erase(exp2.begin() + j);
						j = -1; // 문제의 조건에 앞에서부터 같은 연산자를 처리하라고 해서 다시 검토시키기 위한 부분
						break;
					case '+':
						v2[j] = v2[j] + v2[j + 1];
						v2.erase(v2.begin() + j + 1);
						exp2.erase(exp2.begin() + j);
						j = -1;
						break;
					case '-':
						v2[j] = v2[j] - v2[j + 1];
						v2.erase(v2.begin() + j + 1);
						exp2.erase(exp2.begin() + j);
						j = -1;
						break;
					}
				}
			}
		}

		if (answer < abs(v2[0])) answer = abs(v2[0]); // 절대 값의 크기와 현재 최대 값을 비교한다.
	} while (next_permutation(ep.begin(), ep.end())); // 순열을 알아서 만들도록 설정
       
    return answer;
}
