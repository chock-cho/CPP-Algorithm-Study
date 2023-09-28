#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<iostream>

using namespace std;

map<string,int> combination;

void dfs(string order, int len,string s, int idx){
    if(s.length()==len){
        combination[s]++;
        return;
    }
    
    for(int i=idx;i<order.length();i++){
        dfs(order,len,s+order[i],i+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int len:course){
        for(string order:orders){
            sort(order.begin(),order.end()); //WXA 이런게 있을 수 있어서 sort
            dfs(order,len,"",0); 
        }
        
        int maxCount=0;
        for(auto it:combination){
            
            maxCount=max(maxCount,it.second); //n개 조합 중 가장 많이 주문한 개수
        }
        
        for(auto it:combination){
            if(maxCount<2) break; 
            
            //2명 이상이라면
            else if(combination[it.first]==maxCount)
                answer.push_back(it.first);
        }
        
        combination.clear();
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}
