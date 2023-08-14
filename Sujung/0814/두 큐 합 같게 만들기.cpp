#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    ll sum1, sum2 = 0;
    queue<int> q1, q2;
    
    for(int i : queue1){
        q1.push(i);
        sum1 += i;
    }
    for(int i : queue2){
        q2.push(i);
        sum2 += i;
    }
    if((sum1+sum2)%2!=0){
        // 두 큐에 있는 값의 합이 홀수라면
        return -1;
    }
    int N = sum1 * 3 ;
    int answer = 0;
    
    while(N--){
        if(sum1 == sum2){
            return answer;
        }
        else if(sum1 < sum2){
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum1 += tmp;
            sum2 -= tmp;
            answer++;   // 횟수 증가
        }
        else {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum2 += tmp; 
            sum1 -= tmp; 
            answer++;   // 횟수 증가
        }
    }
    return -1;
}
