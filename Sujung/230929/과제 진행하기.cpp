// 과제 진행하기.cpp 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string,int> info;

bool cmp(vector<string> s1, vector<string> s2){
    return s1[1] < s2[1];
    // 시작시간 순으로 정렬
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<info> waitTasks;
    sort(plans.begin(), plans.end(), cmp);
    
    int curTime = 0;   // 현재 시각
    for(vector<string> plan: plans){
        int planTime = 60*stoi(plan[1].substr(0,2))+ stoi(plan[1].substr(3,5));
        // 시작시각을 분 단위로 변경하여 저장
        
        while(curTime < planTime){
            // planTime에 해당하는 과제 시작 할 수 O
            if(waitTasks.size() > 0){
                // 대기 큐에 있는 과제가 있다면
                waitTasks.back().second--; 
                // 가장 끝에 위치한 과제 꺼내서 진행(해당 시간은 감소)
                if(waitTasks.back().second == 0){
                    // 가장 끝에 위치한 과제를 다 진행하면
                    answer.push_back(waitTasks.back().first);   // 해당 과제 정보(과제 과목 이름)을 answer 벡터에 저장
                    waitTasks.pop_back();
                    // 과제 대기 큐에서는 pop back해주기
                }
            }
            curTime++;
        }
        waitTasks.push_back({plan[0], stoi(plan[2])});
    }
    
    while(waitTasks.size()>0){
        answer.push_back(waitTasks.back().first);
        waitTasks.pop_back();
    }
    return answer;
}
