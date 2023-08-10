#include <string>
#include <vector>
#include <limits.h> 
#include<algorithm>
#include<iostream>

using namespace std;

long long dp[500010];
long long solution(vector<int> sequence) {
    long long answer = 0;
    long long maxSum=dp[0];
    long long maxSum2=dp[0];
    vector<int> v1;
    vector<int> v2;

    if(sequence.size()==1){ //사이즈가 1일 때
        return max(sequence[0],-1*sequence[0]);
    }
        
    int a=1;
    
    for(int i=0;i<sequence.size();i++){ //1, -1 ... 곱해주기
        v1.push_back(a*sequence[i]);
        a*=-1;
        dp[i]=v1[i];
        
    }

    for(int i=1;i<sequence.size();i++){
        dp[i]=max(dp[i],dp[i-1]+v1[i]); //자신이 큰지 앞의 것과 더하는 게 큰지
        if(dp[i]>maxSum){ //maxSum보다 크다면 업데이트
            maxSum=dp[i];
        }
    }
    
    a=-1;

    for(int i=0;i<sequence.size();i++){//-1, 1 ... 곱해주기
        v2.push_back(a*sequence[i]);
        a*=-1;
        dp[i]=v2[i];
        
    }
    
      for(int i=1;i<sequence.size();i++){
        dp[i]=max(dp[i],dp[i-1]+v2[i]);
        if(dp[i]>maxSum2){
            maxSum2=dp[i];
        }
    }
 
    answer=max(maxSum,maxSum2); 

    return answer;
}
