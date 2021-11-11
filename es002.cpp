#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    else
    {
        for(int i = 2; i <= sqrt(n) ; i++)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
}


int solution(string numbers) 
{
    int answer = 0;
    set<int> num_set; vector<string> nums;
    
    for (int i = 0; i < numbers.length(); i++)
    {
        nums.push_back(to_string(numbers[i] - '0'));
    }
    sort(nums.begin(), nums.end());
    
    int length = numbers.length();
    do {
        for (int sel = 0; sel < length; sel++)
        {
            string n = "";
            for (int i = 0; i <= sel; i++)
            {
                n += nums[i];
            }
            int x = stoi(n);
            if (isPrime(x) == true) num_set.insert(x);
        }      
    } while (next_permutation(nums.begin(), nums.end()));
    
    answer = num_set.size();
    return answer;
}
