// 프로그래머스 코딩테스트 연습
// LV2 : 2개 이하로 다른 비트

#include <string>
#include <vector>
using namespace std;
#define ll long long

vector<long long> solution(vector<long long> numbers) {
    vector<long long> result;
    for (int i = 0; i < numbers.size(); i++)
    {
        ll num = numbers[i];
        ll cnt = 0;
        while (true)
        {
            if ((num & 1ll << cnt) == 0) break;
            cnt++;
        }
        if (cnt != 0)
        {
            ll temp = 1ll << (cnt - 1);
            num = num + (1ll << cnt) - temp;
        }
        else
        {
            num += 1ll << cnt;
        }
        result.push_back(num);
    }
    return result;
}
