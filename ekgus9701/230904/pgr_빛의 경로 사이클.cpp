#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int N,M;

//Visit[A][B][C] = true 의 의미는 "(A , B)에 진행방향 'C'로 방문한 적이 있습니다" 를 의미
bool visited[510][510][4];

vector<string> MAP;

//상 하 우 좌
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int change_dir(char c,int dir){
    if(c=='L'){ //L이면
        if(dir==0) return 3; //위로 가고있었으면 왼쪽으로 
        if(dir==1) return 2; //아래로 가고 있었으면 오른쪽으로
        if(dir==2) return 0; //오른쪽으로 가고있었으면 위로
        if(dir==3) return 1; //왼쪽으로 가고있었으면 아래로
    }
    else{
        if(dir==0) return 2; 
        if(dir==1) return 3;
        if(dir==2) return 1; 
        if(dir==3) return 0;
    }

}

int simulation(int x, int y, int dir, int len){
    //(x,y)에 dir방향으로 오는게 중복이면 len을 리턴
    if(visited[x][y][dir] ==true) return len;
    
    visited[x][y][dir]=true;
    
    int nx=x;
    int ny=y;
    int nd=dir;
    //방향 바꾸기
    if(MAP[x][y]!='S') nd=change_dir(MAP[x][y],dir);
    nx=x+dx[nd];
    ny=y+dy[nd];
    //범위 벗어나면 
    if(nx<0) nx=N-1;
    if(ny<0) ny=M-1;
    if(nx==N) nx=0;
    if(ny==M) ny=0;
    
    return simulation(nx,ny,nd,len+1);
    
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    N=grid.size();
    M=grid[0].size();
    MAP=grid;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                int result=simulation(i,j,k,0);
                
                if(result!=0){ //사이클의 길이가 0이라면 중복된 사이클이기 때문에
                    answer.push_back(result);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
