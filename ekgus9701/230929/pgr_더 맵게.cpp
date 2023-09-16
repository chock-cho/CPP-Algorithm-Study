#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue pq{greater<int>{}, scoville};
    
    while(true){
        //cout<<pq.top()<<endl;
        if(pq.size()==1){
            if(pq.top()<K){
                return -1;
            }
        }
        if(pq.top()<K){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int sum=a+b*2;
            pq.push(sum);
            answer++;
                
        }
        else{
            return answer;
        }
        
    }
    
    return answer;
}
