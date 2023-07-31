#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
입력 : 입국심사 기다리는 사람 수, 각 심사관이 한 명을 심사하는데 걸리는 시간 times
출력 : 모든 사람이 심사를 받는데 걸리는 시간의 최솟값
*/

long long solution(int n, vector<int> times) {

    // 이분탐색을 위한 정렬
    sort(times.begin(),times.end());

    // 이분탐색
    long long left = 1; // 가장 짧은 시간
    long long right = (long long)times[times.size()-1] * n; // 가장 긴 시간
    long long mid = (left+right)/2; // 중간 시간
    long long answer = right; 

    while(left <= right){

        // mid 시간동안 심사할 수 있는 사람 수
        long long cnt = 0;
        for(int i=0;i<times.size();i++){
            cnt += mid/times[i];
        }

        // mid 시간동안 심사할 수 있는 사람 수가 n보다 크거나 같을 경우
        if(cnt >= n){
            answer = min(answer,mid);
            right = mid-1;
        }
        // mid 시간동안 심사할 수 있는 사람 수가 n보다 작을 경우 (시간이 부족함)
        else{
            left = mid+1;
        }

        mid = (left+right)/2;
    }

    return answer;
}
