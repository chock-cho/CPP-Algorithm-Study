#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;


int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //이런 식으로 생각하면 쉬움
    //7
    //3 8
    //8 1 0
    //2 7 4 4
    //4 5 2 6 5
    
     dp[0][0]=triangle[0][0];
    //dp[1][0]=triangle[1][0]+dp[0][0];
    //dp[1][1]=triangle[1][1]+dp[0][0];
    //dp[2][0]=triangle[1][0]+dp[1][0];
    //dp[2][1]=triangle[2][1]+max(dp[1][0],dp[1][1]);

    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){ //가장 왼쪽에 있는 수들의 경우
                dp[i][j]=triangle[i][j]+dp[i-1][j];
            }
            
            else if(j==triangle[i].size()-1){ //가장 오른쪽에 있는 수들의 경우
                dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            }
            
            else{ //가운데에 있는 수들의 경우
                dp[i][j]=triangle[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
            }
            
           
        }
       
    }
    
    //가장 아래칸의 최댓값 구하기
    for(int i=0;i<triangle[triangle.size()-1].size();i++){
        answer=max(answer,dp[triangle.size()-1][i]);
    }
    
    
    return answer;
}
