#include <string>
#include <vector>

using namespace std;

/*
입력 : 지점의 개수 n, 출발지점을 나타내는 s, A의 도착지점 a, B의 도착지점 b, 
        지점 사이의 예상 택시요금 나타내는 fares
출력 : 최저 예상 택시요금 
    // 만약 아예 합승을 하지 않고 각자 이동하는 경우의 예상 택시요금이 낮다면, 합승하지 않아도 됨

내용 : 플로이드 와샬 
        - 핵심코드 : dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
        - 모든 정점 k를 거쳐 i에서 j로 가는 최솟값들을 갱신함 
*/

#define MAX 20000000
int dp[201][201]; // "[start][end] = 최소요금" 저장하는 배열 

int solution(int n, int START, int A, int B, vector<vector<int>> fares) {
    
    // 주어진 n (지점 개수)에 따라 dp 배열 초기화
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){
            
            // 시작지점==도착지점
            if(i==j) dp[i][j]=0; // 택시요금 없음
            
            // 그 외의 경우 
            else dp[i][j]=MAX; // 일단 MAX 값으로 초기화 (경로가 없는 부분은 최대로 해놔야 함)

        }
    }

    // 주어진 fares 정보로 dp 배열 초기화
    for(int i=0;i<fares.size();i++){
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];  
    }

    // 경유지점 idx 를 순회하면서 
    for(int mid=1;mid<=n;mid++){ 
        for(int start=1;start<=n;start++){
            for(int end=1;end<=n;end++){
                // 각 지점 별로 min 값 갱신 
                dp[start][end] = min(dp[start][end],dp[start][mid]+dp[mid][end]);
            }
        }
    }

    int min_fares = MAX; // 일단 MAX 값으로 초기화
    
    // 최소 요금 찾기 
    for(int node=1;node<=n;node++){
        min_fares = min(min_fares,dp[START][node]+dp[node][A]+dp[node][B]);
    }

    return min_fares;
}
