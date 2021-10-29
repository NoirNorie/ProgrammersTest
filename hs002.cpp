#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���ڿ��� ������ ��� ���� ������ ���ĵȴ�
// 12, 123, 13 ������ ���ĵ�
// �� �ڷθ� ���ص� �Ǵ� ��쿡 �ش�ȴ�.

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