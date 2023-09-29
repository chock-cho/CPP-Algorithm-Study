// 디펜스 게임.cpp 
// min heap 구현된 priority_queue 이용
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    // min heap = top값에는 가장 작은 값이 위치해있음
    for(int i = 0; i < enemy.size(); i++){
        pq.push(enemy[i]);  
        if(pq.size() > k) {
            // 무적권 개수보다 pq에 담긴 값이 더 많아지면
            sum += pq.top();
            // 적은 공격인 순서대로 병사를 소모해준다.
            pq.pop();
        }
        if(sum > n) {
           return i;
        }
    }
    return enemy.size();
}
