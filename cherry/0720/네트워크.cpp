#include <string>
#include <vector>
#define MAX 200
using namespace std;

    /* 
    <문제정보>
    a-b b-c -> a-c 가능 -> a,b,c 같은 네트워크 상에 존재
    컴퓨터 개수 cnt // 정보 담긴 2차원 배열 computers
    dfs로 풀기 
    */

bool isVisited[MAX];

void dfs(int cur,int num,vector<vector<int>> computers){
    
    isVisited[cur]=true;  // 방문노드 기록
    for(int i=0;i<num;i++){
        // 아직 방문하지 않았고, 연결되어 있으면
        if(!isVisited[i]&&computers[cur][i]==1){ 
            dfs(i,num,computers);
        }
    }
}

int solution(int num, vector<vector<int>> computers) {
    int networks = 0; 
    
    for(int i=0;i<num;i++){
        if(!isVisited[i]){ // 아직 방문하지 않았다면, 
            //(이유 : 연결되어 있는 컴퓨터들은 이미 방문 됐을 것임)
            /* 네트워크 탐색*/
            dfs(i,num,computers);
            networks++;
        }
    }
    return networks;
}
