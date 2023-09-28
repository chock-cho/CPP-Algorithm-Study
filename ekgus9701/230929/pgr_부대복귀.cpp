#include <string>
#include <vector>
#include<climits>
#include<queue>

using namespace std;

//&을 쓰냐 마냐에 따라 시간초과가 일어나고 안일어나고 함!!!
int bfs(vector<vector<int>> &info,int dest, int src){
    int visited[100001]={0};
    
    queue<pair<int,int>> q;
    int result=INT_MAX;
    q.push({src,0});
    visited[src]=1;
    
    while(!q.empty()){
        int curLoc=q.front().first;
        int curCnt=q.front().second;
        q.pop();
        
        if(curLoc==dest){
            result=curCnt;
        }
        
        for(int i=0;i<info[curLoc].size();i++){
            if(visited[info[curLoc][i]]) continue;
            
            visited[info[curLoc][i]]=1;
            q.push({info[curLoc][i],curCnt+1});
        }
    }
    
    return result;
    
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> info(n+1);
    
    for(int i=0;i<roads.size();i++){ //초기 연결
        info[roads[i][0]].push_back(roads[i][1]);
        info[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0;i<sources.size();i++){
        
        if(sources[i]==destination){ //이미 복귀한 상태면
            answer.push_back(0);
            continue;
        }
        int temp=bfs(info,destination,sources[i]);
        
        int ans= temp==INT_MAX?-1:temp; //temp가 업데이트가 안됐으면 -1, 아니면 temp를 넣어줌
        answer.push_back(ans);
    }
    
    
    return answer;
}
