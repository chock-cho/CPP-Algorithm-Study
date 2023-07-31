#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007
int dp[5000]; // dp[i] : 길이가 3 x n 인 직사각형의 타일을 채우는 경우의 수

// dp[n] = dp[n-2] * dp[2] + 2;

int solution(int n) {
   
    dp[2]=3;
    
    int cnt = 2; // 접합부를 교차할 수 있는 경우의 수 
    for(int i=4;i<=n;i+=2){
        dp[n] = dp [n-2] * dp[2] + cnt;
    	cnt+=2;
        dp[n] %=MOD;
    }
    
    return dp[n];
}