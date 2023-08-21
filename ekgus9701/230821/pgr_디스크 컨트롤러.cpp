#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    
    //작업시간 오름차순 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    
    int idx = 0, time = 0;
    
    while (idx < jobs.size() || !pq.empty()) {
        //pq에 넣을 작업이 아직 남았고 현재 시간이 작업 요청 시간보다 크다면
        if(idx < jobs.size() && time >= jobs[idx][0]) {  
            pq.push(make_pair(jobs[idx][1], jobs[idx][0])); //작업 push
            idx++;
            continue;
        }
        
        if(!pq.empty()) { //pq가 비지 않았다면
            time += pq.top().first; // 현재 시간 업데이트
            answer += time - pq.top().second; // 기다린 시간 더해줌
            pq.pop();
        }
        
        else { //pq가 비어있지 않으면
            time = jobs[idx][0]; //다음 작업시간으로
        }
    }
    
    return answer / jobs.size();
}
