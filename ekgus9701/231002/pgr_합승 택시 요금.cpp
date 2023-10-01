#include <string>
#include <vector>

using namespace std;

const int INF=20000001; //지점 개수* 요금 f의 최댓값 -> 200*100000

//플로이드 와샬 알고리즘 사용
//각 정점을 거쳐서 가는 최단경로를 배열에 저장하고 계속 업데이트해줌
/*
  1 2 3 4 5
1 1
2   1
3     1
4       1
5         1

*/
  

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
    
    for(int i=0;i<fares.size();i++){ //초기 연결
        graph[fares[i][0]][fares[i][1]]=fares[i][2];
        graph[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    
    for(int i=1;i<=n;i++){ //자기자신으로 가는 것은 0으로 초기화
        graph[i][i]=0;
    }
    
    //i에서 j로 갈 때 각 정점(k)을 거쳐서 가는 최솟값을 업데이트
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
                
                /*
                    위처럼 쓰는게 아래보다 효율성 측면에서 더 좋음, 대입이 연산보다 느리기 때문!
                    graph[i][j]=min(graph[i][k]+graph[k][j],graph[i][j]);
                */
            }
        }
    }
    
    for(int i=1;i<=n;i++){ //최솟값 업데이트
        if(answer>graph[s][i]+graph[i][a]+graph[i][b]){
            answer=graph[s][i]+graph[i][a]+graph[i][b];
        }
    }
    
    
    return answer;
}
