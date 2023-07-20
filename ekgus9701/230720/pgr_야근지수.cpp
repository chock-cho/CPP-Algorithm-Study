#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int top;
    
    priority_queue<int> pq;
    
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    
    while(true){
        if(n<=0){
            break;
        }
        top=pq.top();
        
        if(top<=0){
            break;
        }
        pq.pop();
        pq.push(top-1);
        n--;

    }
   
    while(!pq.empty()){
        answer+=pq.top()*pq.top();
        pq.pop();
    }

    return answer;
}
