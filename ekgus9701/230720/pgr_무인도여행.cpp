#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

vector<int> answer;
bool visited[101][101];
//좌우상하
int dx[]={1,-1,0,0}; 
int dy[]={0,0,1,-1};

void bfs(vector<string> maps,int k,int j){
    queue<pair<int,int>> q;
    q.push({k,j});
    visited[k][j]=true; //방문 표시
    
    int result=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        
        result+=(maps[x][y]-'0');
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx >= maps.size() || ny >= maps[k].size() || visited[nx][ny]) { 
                //범위를 벗어났거나 방문을 이미 했으면 넘어감
                continue;
            }
            
            if(maps[nx][ny]!='X'){ //X가 아니면
                visited[nx][ny]=true; //방문 표시
                q.push({nx,ny});
            }
        }
        
        
    }
    answer.push_back(result);
}

vector<int> solution(vector<string> maps) {
     
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[i].size(); j++) {
            if(maps[i][j] != 'X' && !visited[i][j]) {
                bfs(maps,i,j);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    if(answer.size() == 0) { 
        answer.push_back(-1);
    }
    
    return answer;
}
