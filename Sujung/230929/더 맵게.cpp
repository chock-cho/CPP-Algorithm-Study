#include <string>
#include <vector>
#include <queue>    // 우선순위 큐 stl 추가
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    // 우선순위 큐 생성 : greater이면 min heap
    // scoville.begin(), scoville.end() 연산을 통해 pq에 삽입해준다
    while(pq.size() >= 2 && pq.top() < K){
        int t1 = pq.top();
        pq.pop();
        
        int t2 = pq.top();
        pq.pop();
        
        int tmp = t1 + 2 * t2;  // 해당 음식 두개 섞기
        pq.push(tmp);
        answer++;   // 섞은 횟수 증가
    }
    
    if(!pq.empty() && pq.top() < K){
        return -1;
    }
    return answer;
}
