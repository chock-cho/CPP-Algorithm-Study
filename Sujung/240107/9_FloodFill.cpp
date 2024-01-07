/*  Flood Fill - bfs 로 풀이하였습니다. */
typedef pair<int,int> pi;
class Solution {
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int w = image.size(); // 가로
        int h = image[0].size(); // 세로

        vector<vector<bool>> vis(w, vector<bool>(h, 0));
        queue<pi> q;
        
        int init_color = image[sr][sc]; // 초기 색깔 기억해두기
        image[sr][sc] = color; // 주어진 색깔 값으로 변경
        vis[sr][sc] = true;
        q.push({sr, sc});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= w || nc >= h) continue;
                if(vis[nr][nc]) continue;
                if(image[nr][nc] != init_color) continue;

                image[nr][nc] = color;
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        return image;
    }
};
