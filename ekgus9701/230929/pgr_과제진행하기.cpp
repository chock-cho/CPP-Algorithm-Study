#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(vector<string> v1,vector<string> v2){
    return v1[1]<v2[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string,int>> waitTask;
    
    sort(plans.begin(),plans.end(),cmp); //정렬
    
    int time=0;
    
    for(vector<string> v:plans){
        int newTime=60*stoi(v[1].substr(0,2))+stoi(v[1].substr(3,2));
        
        while(true){
            //cout<<newTime<<" "<<time<<endl;
            if(time>=newTime){ 
                break;
            }
            
            if(waitTask.size()>0){
                waitTask.back().second--; //1분씩 감소시키기
                if(waitTask.back().second==0){ //0이 되었으면 
                    answer.push_back(waitTask.back().first); //완료한 과제에 넣어주기
                    waitTask.pop_back();
                }
            }
            time++;
        }
        waitTask.push_back({v[0],stoi(v[2])});
    }
     while(waitTask.size()>0){ //최근에 멈춘 과제를 다시 시작하니까 순서대로 빼주면 됨
        answer.push_back(waitTask.back().first);
        waitTask.pop_back();
    }
    
    
    return answer;
}
