#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi, int> pii;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Point {
    int row;
    int col;
    int dist;
};

bool inRange(int x, int y){
    return (x >= 0 && x < 5) && (y >= 0 && y < 5);
}

bool BFS(vector<string> place, int row, int col){
    vector<vector<bool>> vis(5, vector<bool>(5, false));
    queue<Point> q;
    
    vis[row][col] = true;
    q.push({row, col, 0});
    
    while(!q.empty()){
        Point cur = q.front();
        q.pop();
        
        if(cur.dist > 2) continue;
        if(cur.dist != 0 && place[cur.row][cur.col] == 'P')
            return false; // 맨해튼 거리가 지켜지지 않았으므로 false리턴
        for(int i = 0; i < 4; i++){
            int nx = cur.row + dx[i];
            int ny = cur.col + dy[i];
            if(!inRange(nx, ny)) continue;  // 범위 벗어나면 제끼고
            if(vis[nx][ny]) continue;       // 이미 방문한 좌표라면 제끼고
            if(place[nx][ny] == 'X') continue;  // 파티션이라면 제끼고
            vis[nx][ny] = true;
            q.push({nx, ny, cur.dist+1});
        }
    }
    return true;
}

bool chk(vector<string> place){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(place[i][j] == 'P') {
                if(!BFS(place, i, j)) 
                    return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places){
        if(chk(place)) 
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}
