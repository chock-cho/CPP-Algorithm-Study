#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> prior, int loc) {
    int ans=0;
    int size=prior.size();
    queue<pair<int, int>> q; //(중요도, 인덱스)를 저장하는 큐

    for (int i=0;i<size;i++) q.push(make_pair(prior[i], i));
    
    while (!q.empty()) {
        int curPrior = q.front().first;
        int curIdx = q.front().second;
        q.pop();

        bool isMaxPrior = true; // 현재 프로세스가 최우선 순위인지 확인하는 변수

        // 큐에 남아있는 프로세스들과 중요도 비교
        queue<pair<int, int>> temp = q; // 중요도 비교를 위해 임시 큐 생성

        while (!temp.empty()) {
            int priority = temp.front().first;
            temp.pop();

            if (priority>curPrior) { // 중요도가 더 높은 프로세스가 있다면
                isMaxPrior=false; // 현재 프로세스는 최우선 순위가 아님
                break;
            }
        }

        if (isMaxPrior) { // 현재 프로세스가 최우선 순위라면
            ans++; // 실행 순서 증가
            if (curIdx==loc) {return ans;} // 목표 프로세스라면 실행 순서 반환
            
        } else { // 최우선 순위가 아니라면 다시 큐에 넣음
            q.push(make_pair(curPrior, curIdx));
        }
    }
    return ans;
}
