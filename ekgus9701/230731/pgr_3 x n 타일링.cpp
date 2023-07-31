#include <string>
#include <vector>

using namespace std;

long long dp[5005];

int solution(int n) {
    int answer = 0;
    /*
    n = 2 일 때 3가지,
    n = 4 일 때 11가지,
    n = 6 일 때 41가지
    -> dp[n]=dp[n-2]*4+dp[n-4]
    */
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    dp[3]=0;
    for(int i=4;i<=n;i++){
        //모듈러연산의 분배법칙 이용
        //(A - B) % p = ((A % p) - (B % p) + p) % p
        dp[i]= ((dp[i-2]*4)%1000000007-(dp[i-4]%1000000007)+1000000007)%1000000007;
    }
    return dp[n];
}
