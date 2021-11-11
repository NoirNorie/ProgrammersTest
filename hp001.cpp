#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> st;
    multiset<int>::iterator iter;
    for (auto e : scoville) st.insert(e); // 알아서 정렬되어 들어감
    while (*st.begin() < K) // 멀티셋의 시작 값이 원하는 맵기보다 작을 때까지 반복됨
    {
        if (st.size() == 1 && *st.begin() < K) // 섞었는데 답이 없다면
        {
            answer = -1;
            break;
        }
        
        iter = st.begin();    
        advance(iter, 1); // 뒤에서 두번째 맵기 값을 찾아낸다.
        st.emplace(*st.begin() + (*iter * 2));
        st.erase(st.begin()); st.erase(st.begin()); // 앞에 두개를 섞었으므로 제거한다.
        
        answer++;
    }
    return answer;
}

// 우선순위 큐 해결법
/*
#include <queue>

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    // 이렇게 벡터를 옮겨버릴 수도 있다.

    while(pq.top()<K) {
        if(pq.size()==1) return answer = -1;
        needHot=pq.top(); pq.pop();
        pq.push(needHot+pq.top()*2);
        pq.pop(); answer++;
    }

*/
