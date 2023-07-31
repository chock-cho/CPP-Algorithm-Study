#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    if(land.size()==1){ //행이 1일때 최댓값 구하기
        answer=max(land[land.size()-1][0],max(land[land.size()-1][1],max(land[land.size()-1][2],land[land.size()-1][3])));
    }

    else{ 

        for(int i=1;i<land.size();i++){
            land[i][0]+=max(land[i-1][1],max(land[i-1][2],land[i-1][3])); //열이 0이면 그 윗행의 1,2,3열의 최댓값을 더한다
            land[i][1]+=max(land[i-1][0],max(land[i-1][2],land[i-1][3]));
            land[i][2]+=max(land[i-1][0],max(land[i-1][1],land[i-1][3]));
            land[i][3]+=max(land[i-1][0],max(land[i-1][1],land[i-1][2]));
        }
        
        //가장 아래 행의 최댓값을 구한다
        answer=max(land[land.size()-1][0],max(land[land.size()-1][1],max(land[land.size()-1][2],land[land.size()-1][3])));
    }
    

    return answer;
}
