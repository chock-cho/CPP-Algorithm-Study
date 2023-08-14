#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll find_ans(vector<int> v){
    ll res;
    vector<ll> dp(v.size()+1);
    dp[0] = v[0];
    for(int i = 1; i < dp.size()-1; i++){
        dp[i] = max(dp[i-1]+v[i], (ll)v[i]);
    }
    res = *max_element(dp.begin(), dp.end());
    return res;
}
ll solution(vector<int> sequence) {
    ll answer = 0;
    // psum, DP 이용
    int N = sequence.size()+1;
    // 연속 펄스 수열 := 2가지 경우의 수열 나올 수 있음
    vector<int> c1(N, 1);   // 짝수번째 idx가 -1
    vector<int> c2(N, 1);   // 홀수번째 idx가 -1
    
    for(int i = 0; i < N; i++){
        if(i%2  == 0){
            c1[i] *= -sequence[i];
        }
        else {
            c2[i] *= -sequence[i];
        }
    }
    answer = max(find_ans(c1), find_ans(c2));
    return answer;
}
