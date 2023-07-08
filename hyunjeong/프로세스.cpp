#include <string>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque<pair<int,int>> dq;
    for(int i=0;i<priorities.size();i++) {
        dq.push_back(make_pair(i,priorities[i]));
    }
    
    while(true) {
        int i=1;
        bool ch = true;
        while(i<dq.size()) {
            if(dq[0].second < dq[i].second) {
                ch = false;
                break;
            }
            i++;
        }
        if(ch) {
            answer += 1;
            if(dq[0].first == location) {
                break;
            }else {
                dq.pop_front();
            }
        }else {
            pair<int, int> p;
            p = dq.front();
            dq.pop_front();
            dq.push_back(p);
        }
    }
    
    return answer;
}
