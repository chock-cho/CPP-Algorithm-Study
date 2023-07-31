#include <string>
#include <vector>
#define MAX 8

using namespace std;

/*
입력 : 유저의 현재 피로도 k, 각 던전의 최소필요피로도, 소모 피로도
출력 : 유저가 탐험할 수 있는 최대 던전 수 answer
*/

int answer = 0; 
bool visited[MAX] = {0};


void dfs(int cnt, int k, vector<vector<int>> &dungeons) {
    
    // 현재 탐험 던전 수가 이전 탐험 던전 수보다 크면 cnt 갱신
    if (cnt > answer) answer = cnt;
    
    for (int i=0; i<dungeons.size(); i++) {

        /*탐험하지 않은 던전이고, 
        해당 던전의 최소필요피로도가 남은 피로도보다 작거나 같으면 해당 던전 탐험*/
        if (!visited[i] && dungeons[i][0] <= k) {
            
            // 방문체크
            visited[i] = true;
            
            // 탐험한 던전 수, 유저 현재 피로도 갱신 후 dfs 수행
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            
            // dfs 수행이 끝난 던전은 다른 경우에서 재탐험할 수 있도록 방문체크해제
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    // 탐험한 던전 수 0으로 시작
    dfs(0, k, dungeons);
    return answer;
}
