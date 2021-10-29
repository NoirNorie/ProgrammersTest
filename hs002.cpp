#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열을 정렬할 경우 사전 순으로 정렬된다
// 12, 123, 13 순으로 정렬됨
// 앞 뒤로만 비교해도 되는 경우에 해당된다.

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size() -1; i++)
    {
        if (phone_book[i].find(phone_book[i-1]) == 0) 
            return answer = false;
        if (phone_book[i + 1].find(phone_book[i]) == 0)
            return answer = false;
    }

    return answer;
}