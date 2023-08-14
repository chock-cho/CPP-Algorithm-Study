#include <string>
#include <vector>
#include <numeric>
#include <queue>
#define ALL(X) X.begin(),X.end()

using namespace std;

/*
<문제설명>
입력 : 길이가 같은 두개의 큐
출력 : 아래 규칙을 만족하기 위해 필요한 작업의 최소 횟수 

내용
1. 하나의 큐를 골라 원소를 추출(pop)
2. 추출된 원소를 다른 큐에 insert 함
3. 각 큐의 원소 합이 같도록 만들기

유의 - 큐는 FIFO 방식
*/

int solution(vector<int> queue1, vector<int> queue2) {

    long long sum1 = accumulate(ALL(queue1),0);
    long long sum2 = accumulate(ALL(queue2),0);
    long long total = sum1+sum2;

    if(total%2!=0) return -1; // 홀수일 경우, return -1

    int answer = 0;
    
    int len = queue1.size();
    int temp;
    deque<int> q1, q2;

    // vector -> queue 로 만들어주기
    while(!queue1.empty()) {
        q1.push_front(queue1.back());
        queue1.pop_back();
    }
    while(!queue2.empty()) {
        q2.push_front(queue2.back());
        queue2.pop_back();
    }

    // push pop 을 통해 원소가 없어지거나 생기는 경우 sum1,sum2 에서 더하고 빼준다

    for(int i = 0; i < 3 * len; i++) { // 계속 반복되다보면 결국 원상태로 돌아오므로 한계를 정하기
        if (sum1 > sum2) {
            sum1 -= q1.front();
            sum2 += q1.front();
            temp = q1.front();
            q1.pop_front();
            q2.push_back(temp);
            answer++;
        }
        else if (sum1 < sum2) {
            sum1 += q2.front();
            sum2 -= q2.front();
            temp = q2.front();
            q1.push_back(temp);
            q2.pop_front();
            answer++;
        }
        else { // 합이 같은 경우. 끝
            return answer;
        }
    }
    return -1; // 원소 총합이 짝수이고, 어떤 경우로도 합을 같게 할 수 없는 경우.

    return answer;
}
