/*  커스텀 정렬 이용  */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// x좌표 빨리 끝나는 순 -> y좌표 빨리 끝나는 순 
bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);  // 커스텀 정렬 이용
    int target = targets[0][1];
    for(int index = 1; index <= targets.size() - 1; index++) {
        
        if(target > targets[index][0]) {
            target = min(target, targets[index][1]);
        }
        else {
            answer++;
            target = targets[index][1];
        }
    }
    answer++;
    return answer;
}
