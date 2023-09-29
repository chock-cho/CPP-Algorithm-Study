#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
   
    int cnt=0;
    priority_queue<int> pq;
    int i=0;
    
    while(true){
        if(i==enemy.size()) break;
        if(k==0) {
            if(n<enemy[i]) break;
        }
        n-=enemy[i];
        
        //싸운 적의 수를 priority queue에 넣어줌
        pq.push(enemy[i]);
        
        //만약 n이 0보다 작아지면 지금까지 가장 많은 병사를 사용한 라운드에서 무적권을 쓴다
        if(n<0){ 
            k--;
            n+=pq.top();
            pq.pop();
        }
        
        cnt++;
        i++;

    }

    return cnt;
}
