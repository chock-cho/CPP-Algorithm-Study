#include <string>
#include <vector>
#include <queue>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1,a,b;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(i,priorities[i]));
    }
    
    sort(priorities.rbegin(),priorities.rend());
    
    while(true){
        if(q.empty()){
            break;
        }
        
        
        if(q.front().second==priorities[0]){ //우선순위 가장 높은 것과 큐의 첫 인덱스의 값이 같을 때
            if(q.front().first==location){
                return answer;
            }
            else{
                answer++;
                priorities.erase(priorities.begin()+0);
                q.pop();
            }
            
        }
        
        else{
            a=q.front().first;
            b=q.front().second;
            
            q.pop();
            q.push(make_pair(a,b));
            
        }
        
    }
    
    
    
    
    
    return answer;
}
