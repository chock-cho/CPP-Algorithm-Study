#include <string>
#include <vector>
#include<cstring>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int visit[5][5]={0};

bool bfs(vector<string> place, int x, int y, int cnt){
    if(cnt>=3) return true; //맨해튼 거리를 지킨 것
    else if(cnt>0 &&place[x][y]=='P') return false; //맨해튼거리를 지키기전에 P를 만난다면
    
    visit[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx<0||ny<0||nx>=place.size()||ny>=place.size()) continue;
        if(visit[nx][ny]) continue;
        if(place[nx][ny]=='X') continue;
        
        visit[nx][ny]=1;
        if(!bfs(place,nx,ny,cnt+1)) return false; //맨해튼 거리를 지키지 못한 것이므로 false 리턴해서 멈추기
        visit[nx][ny]=0; //방문 처리 취소해주기(계속 탐색해야하니까)
    }
    return true;
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
      for(int p=0; p<5; ++p) {
        int flag = 1;
        for(int i=0; i<5; ++i) {
            for(int j=0; j<5; ++j) {
                if(places[p][i][j] == 'P') { // 사람 위치에서 탐색 시작
                    memset(visit,0,sizeof(visit)); //visit 0으로 초기화
                    
                    if(!bfs(places[p], i, j, 0)) { // 결과 거짓이면 
                        flag = 0;
                        break;
                    }
                }
            }
        }
        
        answer.push_back(flag);
    }
    return answer;
}
