#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
<문제설명>
입력 : jobs 2차원 vector (작업요청시점, 작업소요시간)
출력 : 작업의 요청부터 종료까지 걸린 시간의 최소평균

핵심 : 업무시간 단축 (업무시간이 동일할 경우 업무요청시점이 더 빠른 것이 단축됨)
기준 1. 업무 요청시간이 빠름
기준 2. 소요시간이 적음
*/

// 소요시간이 작은 순으로 정렬
bool cmp(vector <int> &a, vector<int> &b) {return (a[1]<=b[1]);}

int solution(vector<vector<int>> jobs) {
    int works = 0; 
    int current_time = 0; // 현재시각
    int jobs_num = jobs.size(); // 작업 개수

    sort(jobs.begin(),jobs.end(),cmp); // (요청시점, 소요시간) 소요시간 작은순 정렬

    while(!jobs.empty()){
        for(int i=0;i<jobs.size();i++){ // jobs_num 이라고 했을 때 실패 발생
            
            // 현재시각이 업무 요청시점이 되었을 때
            if(jobs[i][0]<=current_time){
                current_time += jobs[i][1];
                works += (current_time-jobs[i][0]); // 일한 시간 추가
                jobs.erase(jobs.begin()+i);
                break;
            }

            // 현재시각이 아직 업무 요청시점이 되지 않았을 때 
            if(i==jobs.size()-1) current_time++;
        }
    }

    return works/jobs_num;
}
