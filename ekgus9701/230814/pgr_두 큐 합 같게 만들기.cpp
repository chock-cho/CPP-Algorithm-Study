#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum=0; //두개의 큐 원소들의 합
    long long sum1=0; //큐 1의 원소들의 합
    long long sum2=0; //큐 2개의 원솓ㄹ의 합
    int temp;
    
    queue<int> q1;
    queue<int> q2;
    
    
    for(int i=0;i<queue1.size();i++){
        sum1+=queue1[i];
        q1.push(queue1[i]);
    }
    for(int i=0;i<queue1.size();i++){
        sum2+=queue2[i];
        q2.push(queue2[i]);
    }
    
    sum=sum1+sum2;
    if(sum%2!=0){//합이 짝수가 아니면 각 큐의 원소합을 같게 만들수 없음
        return -1;
    }
    
    sum/=2; //한 큐에 들어가야할 원소합
    long long chk=0;
    while(true){
         //q1과 q2의 사이즈 합보다 많이 돌면 중단 -> 처음에는 *3을 안했었는데 실패가 나서 여유롭게 해주기 위하여 *3을 해줌
        if(chk>3*(queue1.size()+queue2.size())){ 
            break;
        }
        chk++;
        
        if(sum1==sum2){ //두 큐 합이 같으면
            return answer;
        }
        
        else if(sum1>sum2){ //큐 1 합이 큐 2 합보다 크면 
            //큐 1에서 추출, 큐 2에 넣어주기
            temp=q1.front();
            q1.pop();
            q2.push(temp);
            //합에도 반영
            sum1-=temp;
            sum2+=temp;
            answer++;
        }
        
        else{
            temp=q2.front();
            q2.pop();
            q1.push(temp);
            sum2-=temp;
            sum1+=temp;
            answer++;
        }
        
    }
    //두 큐 합이 같지 않은 것이므로
    return -1;
}
