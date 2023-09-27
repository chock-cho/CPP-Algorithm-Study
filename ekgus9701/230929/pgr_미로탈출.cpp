#include <string>
#include <vector>
#include <climits>
#include <queue>
#include<algorithm>
#include<iostream>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

//스타트에서 레버까지, 레버에서 통로까지 bfs를 두번 돌리면 됨

int bfs(int sx,int sy, int ex, int ey, vector<string> maps){
    int visited[110][110]={0};
    queue<pair<pair<int,int>,int>> q;
    int time=INT_MAX;
    
    q.push({{sx,sy},0});
    visited[sx][sy]=1;
    
    while(!q.empty()){
        int curX=q.front().first.first;
        int curY=q.front().first.second;
        int curTime=q.front().second;
        q.pop();
        
        
        if(curX==ex&&curY==ey){ //통로에 가면
            time=curTime; 
            //cout<<time<<endl;
        }
        
        for(int i=0;i<4;i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            
            if(nx<0||ny<0||ny>=maps[0].size()||nx>=maps.size()){
                continue;
            }
            
            if(maps[nx][ny]=='X'||visited[nx][ny]) continue;
            
            q.push({{nx,ny},curTime+1});
            visited[nx][ny]=1;
            
        }
    }

    return time==INT_MAX ? 0:time;
}

int solution(vector<string> maps) {
   int answer=0;
    pair <int,int> start;
    pair <int,int> lever; 
    pair <int,int> end;
    int cnt=0;
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
           
            if(maps[i][j]=='S'){
                start={i,j};
                
            }
            else if(maps[i][j]=='L'){
                lever={i,j};
                
            }
            else if(maps[i][j]=='E'){
                end={i,j};
               
            }
        }
    }
    
    //startToLever
    int sToL=bfs(start.first,start.second,lever.first,lever.second,maps); //start, lever 위치를 넣어줌
    //cout<<sToL<<endl;
    
    //leverToEnd
    int lToE=bfs(lever.first,lever.second,end.first,end.second,maps); //lever, end 위치를 넣어줌
    
   
    if(lToE&&sToL){ //둘 다 존재하면
        answer=sToL+lToE;
    }
    else{
        answer=-1;
    }
   
    
    
    return answer;
}
