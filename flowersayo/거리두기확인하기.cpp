#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<vector<string>> places) {
    int side[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<int> answer;
    queue<pair<int,pair<int,int>>> q;
    
    for(int p_idx=0;p_idx<5;p_idx++)
    {
        bool flag=false;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(places[p_idx][i][j]=='P')
                {
                    bool visit[5][5];
                    fill(&visit[0][0],&visit[5][6],false);
                    visit[i][j]=true;
                    q.push(make_pair(0,make_pair(i,j)));
                    while(!q.empty())
                    {
                        int len=q.front().first;
                        int y=q.front().second.first;
                        int x=q.front().second.second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int ny=y+side[k][0];
                            int nx=x+side[k][1];
                            if(ny<0&&ny<5&&nx>=0&&nx<5&&visit[ny][nx]==false
                            	&&places[p_idx][ny][nx]!='X')
                            {
                                visit[ny][nx]=true;
                                if(places[p_idx][ny][nx]=='P')
                                {
                                    if(len+1<=2)
                                        flag=true;
                                }
                                else if(places[p_idx][ny][nx]=='O')
                                {
                                    q.push(make_pair(len+1,make_pair(ny,nx)));
                                }
                            }
                        }
                    }
                }
                
            }
        }
        if(flag==true)
            answer.push_back(0);
        else
            answer.push_back(1);
        
    }
    
    return answer;
}