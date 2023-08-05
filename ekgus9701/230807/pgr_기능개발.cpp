#include <string>
#include <vector>
#include<queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt=0;
    queue<int> q;
    int tmp;

    for(int i=0;i<progresses.size();i++){ //q에 옮겨주기
        q.push(progresses[i]);
    }

    while(true){
        
         if(q.empty()){ //q가 비어있으면 셌던 cnt push
             answer.push_back(cnt);
            break;
        }
        
        if(q.front()>=100){ //q의 맨 앞에 있는 기능의 진도율이 100을 넘으면 
            cnt++;
            q.pop();
            speeds.erase(speeds.begin());
            continue; //여러개가 한꺼번에 배포되게 하기 위해서
        }
        else{ 
            if(cnt!=0){ //cnt가 0일때 push되는걸 막기 위해서
                answer.push_back(cnt); //앞서 계산했던 cnt push
                cnt=0;
            }
        }

        for(int i=0;i<q.size();i++){
            tmp=q.front();
            q.pop();
            q.push(tmp+speeds[i]); //작업 진도율 업데이트
        }
        
    }
    
   
    return answer;
}
