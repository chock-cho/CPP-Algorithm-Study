#include <string>
#include <vector>

using namespace std;

/*
<문제설명>
입력 : 격자의 크기 m(열개수), n(행개수) (1이상 100이하)
        , 물 잠긴 지역 좌표를 담은 2차원 배열 puddles (10개 이하)
출력 : 오른쪽과 아래쪽으로만 움직여 집->학교 까지의 최단경로의 개수 / 1,000,000,007

유의할 점 : 지역 idx 1부터 시작하도록 주어짐 
-> dynamic programming
-> 중딩? 때 격자에서 길찾기 했던 것으로 해결함 (모서리에 1씩 더해서 길개수 찾는 방식)
*/

int dp[101][101];

int solution(int column, int row_, vector<vector<int>> puddles) {
    
    dp[1][1] = 1;

    // 물웅덩이는 -1로 표시해두기 
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    for(int row=1;row<=row_;row++){
        for(int col=1;col<=column;col++){
            
            // 경우의 수 담는 변수
            int case_row=0;
            int case_col=0;
            
            // 물 웅덩이 있을 경우 pass
            if(dp[row][col] == -1) continue;

            // 위치에 맞는 경우의 수 update 
            if(dp[row-1][col] != -1) case_row = dp[row-1][col];
            if(dp[row][col-1] != -1) case_col = dp[row][col-1];

            // 경우의 수 update 
            dp[row][col]+=(case_row+case_col)%1000000007;
        }
    }

    return dp[row_][column];
}
