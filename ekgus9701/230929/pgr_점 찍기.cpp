#include <string>
#include <vector>
#include<cmath>

using namespace std;


long long solution(int k, int d) {
    long long answer = d/k+1; //x축 위 점들을 미리 구해둠 +1은 0,0인거 따져준 것
    
    for(long long i=0;i<d;i+=k){ 
        answer+=(long long)(sqrt((long long)d*d-i*i))/k;
    }
    
    //k=2 d=4일 때
    
    //x(i)가 0일 때 -> 2개(y=2,4)
    //      2일 때 -> 1개 (y=2)
    
   
    return answer;
}
