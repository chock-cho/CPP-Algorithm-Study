/*   합승 택시 요금 : 플로이드-와샬, 완전탐색   */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;  

const int INF = 20000001; 
int dist[201][201];         // 지점의 정보를 담고 있는 dist배열
// x, y 지점이 연결돼있으면 cost(가중치)는 dist[x][y] = dist[y][x]

void floydWarshall(int n){
    for(int k = 0; k < n; k++){
        // 경유지 : k
        for(int i = 0; i < n; i++){
            // 출발점 : i
            for(int j = 0; j < n; j++){
                // 도착점 : j
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    // 경유지를 거쳐서 i->j를 가는 게 i->j까지의 경로보다 더 cost가 작다면 
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(auto edge : fares){
        dist[edge[0] - 1][edge[1] - 1] = edge[2];
        dist[edge[1] - 1][edge[0] - 1] = edge[2];
    }
    
    floydWarshall(n);
    s-=1; a-=1; b-=1;

    int answer = INF;
    for(int k = 0; k < n; k++){
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
    }
    return answer;
    
}
