#include <string>
#include <vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    
    sort(times.begin(),times.end());
    
    long long left=0;
    long long right=(long long)times[times.size()-1]*n;
    
    while(left<=right){
        long long mid=(left+right)/2;
        
        long long cnt=0;
        
        for(int i=0;i<times.size();i++){ //mid시간동안 심사받을 수 있는 사람의 수 계산
            cnt+=mid/times[i]; 
        }
        
        if(cnt<n){ //기다리는 사람만큼 심사를 못했다면
            left=mid+1;
        }
        
        else{
            answer=mid;
            right=mid-1; //최솟값을 구해야하니까 right 업데이트
        }
    }
    
    
    return answer;
}
