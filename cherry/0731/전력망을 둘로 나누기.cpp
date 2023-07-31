#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

/*
입력 : 송전탑의 개수 n, 전선정보 wires
내용 : 전선들 중 하나를 끊어 송전탑 개수가 가능한 비슷하도록 전력망 나누기
출력 : 두 전력망이 가진 송전탑 개수 차이의 최솟값
*/

int graph[MAX][MAX] = {0}; // wires 값으로 초기화
vector<bool> visited; // 방문체크 배열

// 둘로 나눠진 전력망의 크기 구하기
int dfs(int cur,int n){

    // 방문했을 경우
    if(visited[cur]) return 0;

    // 방문하지 않았을 경우
    int ret = 1;
    visited[cur] = true;

    for(int i=1;i<=n;i++){

        // 연결되어 있고, 방문하지 않았을 경우
        if(graph[cur][i] == 1){
            ret += dfs(i,n);
        }
    }

    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    // 그래프 초기화 (전선이 연결된 경우 1)
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    // 모든 선을 끊어보며 정답 탐색
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        // 선 끊기
        graph[a][b] = 0;
        graph[b][a] = 0;

        // 방문체크 배열 초기화
        visited.assign(n+1,false);
        
        // 2개로 나뉜 전력망의 크기를 구하기
        int a_cnt = dfs(a,n);
        int b_cnt = dfs(b,n);

        // 두 전력망의 크기 차이 구하기
        int diff = abs(a_cnt - b_cnt);

        // 최소값으로 정답 갱신
        if(answer == -1 || answer > diff) answer = diff;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    return answer;
}
