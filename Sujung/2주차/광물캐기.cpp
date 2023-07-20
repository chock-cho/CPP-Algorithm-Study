#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

map<string, int>MineralList;                //광물들 이름
int AllList[3][3]={{1,1,1},{5,1,1},{25,5,1}}; // 각각 피로도


vector<int>MineralsIntList;

int ListSize=0;
int answer = 1250;

//5 개씩 광물을 캔다....
//곡갱이의 갯수 picks   >> [다이아곡갱이 갯수, 철곡갯수, 돌곡갯수]
// 광물들의 순서 minerals   >> [순서~~~]
// 최소의 피로도는?


// >>> dfs로 찾기 가능?

void dfs(vector<int> &picks, int location,int sum){ // 곡갱이들, 현재 위치
    int sumList[3]={0,}; // 피로도 저장
    int savePoint=0;
    
    if(ListSize<=location || picks[0]+picks[1]+picks[2]==0){// 끝까지가거나 곡갱이다씀
        
        answer=min(answer,sum);
        return;
    }
    
    
    for(int i=location;i<location+5;i++){
        
        if(i>=ListSize){
            savePoint=i;
            break;
        }
        sumList[0]+=AllList[0][MineralsIntList[i]];
        sumList[1]+=AllList[1][MineralsIntList[i]];
        sumList[2]+=AllList[2][MineralsIntList[i]];  // 각각의 곡갱이로 일을한것!
        
        savePoint=i;
    }
    
    
    
    for(int i=0;i<3;i++){//각각 출발
        if(picks[i]!=0){
            picks[i]-=1;
            dfs(picks,savePoint+1,sum+sumList[i]);
            picks[i]+=1;
        }
    }
    
    
}

int solution(vector<int> picks, vector<string> minerals) {
    
    
    MineralList["diamond"]=0; 
    MineralList["iron"]=1;
    MineralList["stone"]=2;
    
    ListSize=minerals.size();
    
    for(string i : minerals){
        MineralsIntList.push_back(MineralList[i]);
    }
    
    
    
    dfs(picks,0,0);
    
    
    return answer;
}