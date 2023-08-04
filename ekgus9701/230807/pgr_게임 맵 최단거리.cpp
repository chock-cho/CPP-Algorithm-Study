#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool visited[101][101]={0}; //방문했는지 체크하는 배열
int check[101][101]={0}; //각 칸을 방문하기 위해 몇개의 칸을 밟아야하는지 저장해둔 배열


void bfs(vector<vector<int> > &maps, int startX, int startY){
    queue<pair<int,int>> q;
    q.push({startX,startY});
    visited[startX][startY]=true;
    check[startX][startY]=1;
    
    while(!q.empty()){

        int curX=q.front().first;
        int curY=q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            
            //상하좌우로 이동
            int X=curX+dx[i]; 
            int Y=curY+dy[i];
            
    
            if(visited[X][Y]!=true && X>=0 &&Y>=0 &&Y<maps[0].size()&&X<maps.size()){ //방문한적 없는 칸인지 && 이동한 칸이 맵 안에 있는지
                if(maps[X][Y]==1){ //갈 수 있는 칸이라면
                    
                    visited[X][Y]=true; //방문표시
                    check[X][Y]=check[curX][curY]+1; //방금 밟은 칸보다 한칸 더 밟은 것이기 때문에 +1
                    q.push({X,Y});
                    //cout<<Y<<" "<<X<<" "<<check[X][Y]<<endl;
                }
            }
        }
    }
    
}

int solution(vector<vector<int> > maps)
{
  
    bfs(maps,0,0); 
    
    if(check[maps.size()-1][maps[0].size()-1]==0){ //끝까지 못갔으면
        return -1;
    }
    else{ //끝까지 간 경우
        return check[maps.size()-1][maps[0].size()-1];
    }
    

}
