/**      4방향 빛 쏴주기->완탐 + DFS + 사이클 조건 활용 문제    **/

/* 

    빛을 쏠때에는 4방향을 다 쏴주면서 DFS 진행.
    
    
    ? 🎯사이클이 생성되는 것의 의미
    
    : 이미 방문한 좌표를 방문했던 방향으로 재방문할때
    "방향"이라는 조건이 하나 붙었으므로 방문캐싱 배열인 vis배열을 3차원으로 선언
    
    vis[r][c][dir] 
    := (r,c)의 좌표 노드에 dir방향으로 빛이 들어온 적 있는지 체킹해주는 방문 배열
    
    ✔️ false로 초기화, true가 되면 사이클이 생성되었으므로 업데이트된 사이클 길이인 depth를 정답 벡터에 밀어넣기
    
 */

#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int N, M;
bool vis[501][501][4];
// vis[r][c][dir]r, c 의 격자에 dir 방향으로 들어온 적이 있는지를 체크하는 배열
vector<string> GRID;
 
int dx[] = { 0, 0, 1, -1 }; 
int dy[] = { 1, -1, 0, 0 };

// 방향 전환함수
int decideDir(char cur, int dir)
{
    if (cur == 'L') // L이 써진 칸에 도달한 경우, 좌회전
    {
        if (dir == 0) return 3;
        if (dir == 1) return 2;
        if (dir == 2) return 0;
        if (dir == 3) return 1;
    }
    // R이 써진 칸에 도달한 경우, 우회전
    if (dir == 0) return 2;
    if (dir == 1) return 3;
    if (dir == 2) return 1;
    if (dir == 3) return 0;
}
 
int DFS(int x, int y, int dir, int depth)
{
    if (vis[x][y][dir] == true) {
        // vis[r][c][dir]: = r, c 의 격자에 dir 방향으로 들어온 적이 있는지를 체크하는 배열, 그렇다면 사이클이 생성된다.
        return depth;
    }
 
    vis[x][y][dir] = true;
 
    int nx = x;
    int ny = y;
    int nd = dir;
 
    if (GRID[x][y] != 'S') { // 조건1: S면 그냥 직진, L이나 R이면 방향전환 필요
        nd = decideDir(GRID[x][y], dir);
    }
    // 완탐해보기
    nx = x + dx[nd];
    ny = y + dy[nd]; 
    //
    
    // 조건2: 격자 끝이 넘어갈 경우에는, 반대쪽 끝으로 다시 돌아온다.
    if (nx < 0) nx = N - 1;
    if (ny < 0) ny = M - 1;
    if (nx == N) nx = 0;
    if (ny == M) ny = 0;
    // 
    
    return DFS(nx, ny, nd, depth + 1);
}
 
vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    N = grid.size();    // N
    M = grid[0].size(); // M
    GRID = grid;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int res = DFS(i, j, k, 0);
                if (res != 0) {
                    answer.push_back(res);
                }
            }
        }
    }
    sort(answer.begin(), answer.end()); // 오름차순 정렬
    return answer;
}
