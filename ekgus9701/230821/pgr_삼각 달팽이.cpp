#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1000][1000];
    int x=0,y=0;
    int state=0;//0->왼쪽 1-> 아래 2-> 오른쪽
    int num=1;
    
    //1
    //2 9
    //3 10 8
    //4 5 6 7
    
    for(int i=0;i<n;i++){
        if(state==0){ //왼쪽
            for(int k=i;k<n;k++){
                arr[x][y]=num;
                x++;num++;
            }
            x--;y++; //아래 채울 준비
            state=1;
        }
        
        else if(state==1){ //아래 채우기
            for(int k=i;k<n;k++){
                arr[x][y]=num;
                y++;num++;
            }
            y-=2;x--; //오른쪽 채울 준비
            state=2;
        }
        else{
            for(int k=i;k<n;k++){ //오른쪽 채우기
                arr[x][y]=num;
                x--;y--;num++;
            }
            y+=1;x+=2; //왼쪽 채울 준비
            state=0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}
