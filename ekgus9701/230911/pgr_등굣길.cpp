#include <string>
#include <vector>

using namespace std;

int dp[110][110];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

     for(int i = 0; i < 110; ++i){ //초기값 -1로 
        for(int j = 0; j < 110; ++j)
            dp[i][j] = -1;
    }
    
    dp[0][0]=1; //시작 점을 1
    
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][0]-1][puddles[i][1]-1]=0; //침수된 부분을 0으로 해서 더해질 때 문제 없게 함
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(dp[i][j]==-1){ //침수된 부분이 아니라면
                if(i==0&&j==0) continue; //시작점은 넘기기
                else if(i==0){
                    dp[i][j]=dp[i][j-1]%1000000007; //윗 행꺼 그대로 가져오기
                }
                else if(j==0){
                    dp[i][j]=dp[i-1][j]%1000000007; //왼쪽 열꺼 그대로 가져오기
                }
                else{
                    //왼쪽과 위쪽방향에서 올 수 있으니까 더해주기
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000007;
                }
            }
            
        }
    }
    
    answer=dp[m-1][n-1];
    
    return answer;
}
