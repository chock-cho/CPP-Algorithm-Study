#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

vector<int> info[101];
int cnt;

void bfs(int v1, int v2){
    queue<int> q;
    vector<bool> visited(101);
    
    q.push(v1);
    visited[v1]=true; //방문 표시
    visited[v2]=true;
    
    //queue를 이용한 bfs 
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(int i=0;i<info[cur].size();i++){
            int next=info[cur][i];
            
            if(visited[next]) continue;
            
            cnt++;
            q.push(next);
            visited[next]=true;
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
   int answer=101;
    
    for(int i=0;i<wires.size();i++){ //연결된 노드들 저장
        info[wires[i][0]].push_back(wires[i][1]);
        info[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0;i<wires.size();i++){
        cnt=1;
        int v1=wires[i][0];
        int v2=wires[i][1];
        
        bfs(v1,v2);
        answer=min(answer,abs(n-2*cnt)); 
        //왼쪽 전력망의 송전탑의 개수: cnt-1, 오른쪽 전력망의 송전탑의 개수: n-cnt-1
    }

    
    return answer;
}
