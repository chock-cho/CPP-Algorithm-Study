#include <string>
#include <vector>
#include <algorithm>
#define MAX 500
using namespace std;

/*
<문제설명>
입력 : 삼각형의 정보
내용 : 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우 -> 한칸씩 이동 가능
출력 : 거쳐간 숫자의 최댓값을 return 

dp[i][j]=(i,j)까지의 최대합이라고 정의
*/

int dp[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1; i<triangle.size();i++){
        for(int j=0; j<triangle[i].size();j++){
            if(j==0){
                dp[i][j]=triangle[i][j]+dp[i-1][0]; // 왼쪽일 경우
            }
            else if(j==triangle[i].size()-1){
                dp[i][j] = triangle[i][j]+dp[i-1][j-1]; // 오른쪽일 경우
            }
            else{
                dp[i][j] = triangle[i][j]+max(dp[i-1][j-1],dp[i-1][j]); // DP 값 삽입
        }
    }
    for(int i=0; i<triangle[triangle.size()-1].size();i++){
    answer = max(answer,dp[triangle.size()-1][i]);    
    }

    return answer;
}
