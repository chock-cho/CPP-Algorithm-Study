#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define MAX 100+1

using namespace std;
/*
<문제설명>
지도 -> 직사각형 격자 형태
각 칸 : x 또는 1~9 사이의 자연수가 적혀있음
x : 바다 , 상하좌우 숫자 연결 땅 -> 무인도 , 숫자 : 식량
상+하+좌+우 -> 무인도에서 최대 머무를 수 있는 시간
*/

vector<int> answer;
bool check[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(vector<string> maps, int k, int j) {
    queue<pair<int,int>> q;
    q.push({k,j});
    check[k][j] = true;
    
    int result = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        result += (maps[x][y] - '0');
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[k].size() || check[nx][ny]) continue;         
            if(maps[nx][ny] != 'X') {
                check[nx][ny] = true;
                q.push({nx,ny});    
            }
        }
    }
    answer.push_back(result);   
}

vector<int> solution(vector<string> maps) {
    
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[i].size(); j++) {
            if(maps[i][j] != 'X' && !check[i][j]) {
                bfs(maps,i,j);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}
