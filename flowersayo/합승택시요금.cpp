#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int INF = 2e7; //최대 가중치 * n-1 <  100,000 * 200

//플로이드-워셜 : 가능한 모든 정점 2개의 조합에 대한 최단 경로를 구하는 ASP 알고리즘 
void floydWarshall(int n, vector<vector<int>>& graph) {
   
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int dist = graph[i][k] + graph[k][j];
                graph[i][j] = min(dist,graph[i][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
   
    int answer = 2*INF;
    vector<vector<int>> graph (n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++){
        graph[i][i] = 0; // 자기자신과의 거리
    }
    
    for(int i=0;i<fares.size();i++){
            graph[fares[i][0]][fares[i][1]]=fares[i][2];
        graph[fares[i][1]][fares[i][0]]=fares[i][2]; //양방향 그래프처리
      
    }
    floydWarshall(n,graph);
    
    
    for(int i=1;i<=n;i++){ // i: 갈라지는 지점
        int cost = graph[s][i]+graph[i][a]+graph[i][b]; // 같이가는 비용 + a까지 비용 + b까지 비용
        answer = min(answer,cost);
    }
    
    return answer;
}