#include <string>
#include <vector>
#include <cmath>

using namespace std;
int answer=INT32_MAX;

/*
<문제설명>
3가지의 곡괭이로 3가지 광물을 캘 때 최소 피로도 구하기
1. 한 곡괭이로 5개까지 캘 수 있음
2. 한 번 든 곡괭이는 끝까지 사용
3. 곡괭이 모두 사용하면 완료된 것으로 취급
!! 곡괭이의 사용 순서에 주목 !!
dfs로 해결
*/

int cnt_tired(int cnt, int idx, vector<int> mine){
    
    int pick = (int)pow(5,2-idx), res = 0;
    // pick : 다이아 = 25, 철 = 5, 돌 = 1
    for(int i=cnt*5;i<(cnt+1)*5 && i<mine.size();i++)
    {
        int num = mine[i] / pick; // 광물을 곡괭이값으로 나눈값.
        if (num == 0) res++; // 곡괭이가 크면 0임
        else res += num;
    }
    return res;
}

void dfs(int cnt, int res, vector<int> picks, vector<int> mine){
    
    // 곡괭이를 다 썻거나, 광물을 다 캤으면
    if ((!picks[0] && !picks[1] && !picks[2]) || cnt*5 >= mine.size()){
        answer = min(answer, res); // 최소값 저장
        return;
    }
    for(int i=0;i<3;i++){
        if(picks[i]){
            picks[i]--; // 곡괭이 개수--
            dfs(cnt+1, res+cnt_tired(cnt,i,mine), picks, mine);
            picks[i]++; // dfs넘겨주고 다시++
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {

    vector<int> mine;
    
    for(auto c : minerals){
        // 광물 : 다이아 = 25, 철 =5, 돌 =1 로 새로운 vector에 저장
        if(c[0]=='d') mine.push_back(25);
        else if(c[0]=='i') mine.push_back(5);
        else mine.push_back(1);
    }
    dfs(0, 0, picks, mine);
    return answer;
}
