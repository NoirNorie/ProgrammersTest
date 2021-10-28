#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
   
    int i = 0;
    while (i < progresses.size())
    {
        int f = i;
        int comp = 0; // ���� �Ϸ�� �׽�ũ ��
        // ���μ����� �ӵ���ŭ ������Ų��.
        for (int t = 0; t < progresses.size(); t++)
        {
            progresses[t] += speeds[t];
        }

        for (; f < progresses.size();)
        {
            // ���� ���μ����� �ϼ����� �ʾҴٸ� ���� ���μ����� �� �ʿ� ����.
            if (progresses[f] < 100) 
            {
                break;
            }
            else // �ϼ� �Ǿ��ٸ�
            {
                comp++; // �Ϸ�� ���μ��� ���� �ϳ� ������Ų��.
                f++; // ���� ���μ��� �˻�
            }
        }

        if (comp != 0) // �ϼ��� ���μ����� �ִٸ�
        {
            answer.push_back(comp);
            i += comp; // ���� �Ϸ�� ���μ��� ��ŭ �����ش�.
        }
    }
    return answer;
}