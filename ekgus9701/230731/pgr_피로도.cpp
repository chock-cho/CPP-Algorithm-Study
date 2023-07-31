#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[8]={0};

void solve(int cur,int cnt, vector<vector<int>> dungeons){ //현재 피로도, 탐험한 던전 수, 던전 벡터를 인자로 넣어줌
    if(cnt>answer){ //탐험한 최대 던전 수 업데이트
        answer=cnt;
    }
    
    for(int i=0;i<dungeons.size();i++){
        if(!visited[i]&&cur-dungeons[i][0]>=0){ //방문하지않았고 현재피로도가 최소필요피로도보다 크면
            visited[i]=true; //방문처리
            solve(cur-dungeons[i][1], cnt+1, dungeons);
            visited[i]=false; //다른 던전에서 재탐험 해야하기 때문에 false처리
        }
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    
    
    solve(k,0, dungeons);
    return answer;
}
