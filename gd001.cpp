#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 5;
    vector<int> lost = { 4, 2 };
    vector<int> reserve = { 3, 5 };
    vector<int> chk(n + 2, 1);
    // �ִ� ũ�� + 2�� ���� ��Ż ����
    // �ϴ� ü������ 1���� �ִٰ� ������

    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    // ���� �Ű� �������� ���� �����ϱ� �ϴ� ��ȣ������ �����ϰ� ó���Ѵ�.

    int answer = 0; answer = n;

    for (int i = 0; i < lost.size(); i++) // �зȴ��� �����
    {
        chk[lost[i]]--;
    }

    for (int i = 0; i < reserve.size(); i++) // ������ �ִ��� �����
    {
        chk[reserve[i]]++; // ������ �� �ִ� ��� üũ
    }


    for (int j = 0; j < lost.size(); j++) // ������ ����
    {
        if (chk[lost[j]] == 0) // ü������ ���ٸ�
        {
            if (chk[lost[j] - 1] > 1) // �ջ������ ���´�
            {
                chk[lost[j] - 1]--; // ������
            }
            else if (chk[lost[j] + 1] > 1) // �޻������ ���´�
            {
                chk[lost[j] + 1]--; // ������
            }
            else // ���� �� ���ٸ�
            {
                answer--; // �信�� �ϳ� ����
            }
        }

    }

    cout << answer << '\n';

    return answer;
}