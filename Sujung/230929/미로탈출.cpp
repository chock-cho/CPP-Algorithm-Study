//  미로 탈출.cpp
// (시작지점->레버) (레버->시작지점)  BFS 2번 돌려준다.
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pi;
const int dx[] = {0, 1, 0, -1}; // 동 서 남 북 
const int dy[] = {1, 0, -1, 0};
int r, c; // row, col 값

bool inRange(int x, int y, int r, int c){
    return (x >= 0) && (x < r) && (y >= 0) && (y < c);
}

int BFS(vector<string>& maps, pi s, pi e, int& r, int& c){
    // s: 시작노드, e: 끝나는 노드
    queue<pi> q; // 페어 큐
    vector<vector<bool>> vis(r, vector<bool>(c, false)); // 방문체크 좌표
    vector<vector<int>> dist(r, vector<int>(c, 0)); // 거리 세어주는 좌표
    vis[s.first][s.second] = true; // 방문 처리해주고
    q.push({s.first, s.second}); // 큐에 밀어넣어주기
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!inRange(nx, ny, r, c)) continue; // 좌표 안이 아니라면 제끼고
            if(vis[nx][ny]) continue; // 이미 방문한 곳이라면 제끼고
            if(maps[nx][ny] == 'X') continue; // 벽이라면 제끼고
            
            vis[nx][ny] = true;     // 방문 처리 해주고
            q.push({nx, ny});       // 큐에 밀어넣기
            dist[nx][ny] = dist[x][y] + 1;  // 아니라면 누적 거리 업로드 하면서 진행
            if(nx == e.first && ny == e.second) {
                // 끝나는 지점이면 그때까지 업로드한 누적거리를 리턴
                return dist[nx][ny];
            }
        }
    }
    if(!vis[e.first][e.second]){
        return -1;
    }
}
int solution(vector<string> maps) {
    int answer = 0;
    int r = maps.size(); 
    int c = maps[0].size(); 
    
    pi start; pi lever; pi end; // 시작, 레버, 끝 지점 좌표 정보
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(maps[i][j] == 'S') { // 시작 좌표
                start = make_pair(i,j);
            }
            else if(maps[i][j] == 'L') { // 레버 좌표
                lever = make_pair(i,j);
            }
            else if(maps[i][j] == 'E'){ // 끝나는 좌표
                end = make_pair(i,j);
            }
        }
    }
    
    int route1 = BFS(maps, start, lever, r, c);
    int route2 = BFS(maps, lever, end, r, c);
    if(route1 < 0 || route2 < 0){
        answer= - 1;
    }
    else {
        answer = route1 + route2;
    }
    return answer;
}
