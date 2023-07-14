
#include <string>
#include <vector>

using namespace std;
int visited[201];

void dfs(int cur, int n, vector<vector<int>> computers){
    visited[cur]=1; //현재 방문했다고 표시
    for(int i=0;i<n;i++){
        if(visited[i]!=1&&computers[cur][i]==1){ //탐색하는 컴퓨터가 방문 안했고 현재 컴퓨터와 연결 된 컴퓨터라면
            dfs(i,n,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(visited[i]==0){ //방문 안했다면
            dfs(i,n,computers); //탐색
            answer++; //이어진 것들 모두 탐색한거니까 answer++
        }
    }
    
    return answer;
}
