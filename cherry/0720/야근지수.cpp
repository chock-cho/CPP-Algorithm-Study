#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int time, vector<int> works) {
    long long answer=0;
    
    // 원래 생각했던 방식 -> 효율도 계산에서 막힘
    // 지수가 최소화 되려면 max 값이 작아지는 방향
    // time 동안 정렬해서 max 값에서 1씩 빼주기
    
    // priority_queue를 정의하고, works에 들어온 작업들을 옮겨담기
    priority_queue<int> q(works.begin(),works.end());
    
    for(int i=0;i<time;i++){
        if(q.top()>0){
            long long tmp=q.top();
            q.pop();
            q.push(tmp-1);
        }
    }
    
    while(!q.empty()) {
        answer+=(q.top()*q.top());
        q.pop();
    }
    return answer;
}
