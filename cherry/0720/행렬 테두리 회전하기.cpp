#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    vector<int> _min_;
    vector<vector<int>> board(rows+1,vector<int>(columns+1));
    
    /*board 만들기*/
    for(int y=1;y<=rows;y++)
        for(int x=1;x<=columns;x++)
            board[y][x]=((y-1)*columns+x);
    
    // 회전하고 min 값 찾기 (4개의 변으로 나눠서 진행)
    for(int i=0;i<queries.size();i++)
    {
        int r1,c1,r2,c2,tmp,mini;
        
        // query대로 좌표설정
        r1=queries[i][0],c1=queries[i][1];
        r2=queries[i][2],c2=queries[i][3];
        
        mini=board[r1][c1];tmp=mini;
        
        // 좌측
        for(int y=r1;y<r2;y++){
            board[y][c1]=board[y+1][c1];
            mini = min(mini,board[y][c1]);
        }
        
        // 하단
        for(int x=c1;x<c2;x++){
            board[r2][x]=board[r2][x+1];
            mini = min(mini, board[r2][x]);
        }
        
        // 우측
        for(int y=r2;y>r1;y--){
            board[y][c2]=board[y-1][c2];
            mini = min(mini,board[y][c2]);
        }
        
        // 상단
        for(int x=c2;x>c1;x--){
            board[r1][x]=board[r1][x-1];
            mini = min(mini,board[r1][x]);
        }
        
        board[r1][c1+1]=tmp;
        _min_.push_back(mini);
    }    
    return _min_;
}
