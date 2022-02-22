// 프로그래머스 코딩테스트 연습
// LV1 : 소수 만들기

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> tmp(nums.size(), 1);
    for(size_t i = 0 ; i < nums.size() - 3; i++)
    {
        tmp[i] = 0;
    }
    
    do
    {
        int p = 0; bool chk = false;
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == 1)
            {
                p += nums[i];
            }
        }
        for (int i = 2; i * i <= p; i++)
        {
            if (p % i == 0)
            {
                chk = true;
            }
        }
        if (chk == false)
        {
            answer++;
        }        
    }while(next_permutation(tmp.begin(), tmp.end()));

    return answer;
}
