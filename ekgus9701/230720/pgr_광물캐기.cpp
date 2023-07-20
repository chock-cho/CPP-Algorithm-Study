#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

map<string, int> MineralList;                //광물들 이름 저장할 리스트
int AllList[3][3]={{1,1,1},{5,1,1},{25,5,1}}; // 각각 피로도

vector<int>MineralsIntList;

int ListSize=0;
int answer = 1250;



void dfs(vector<int> &picks, int location,int sum){ 
    int sumList[3]={0,}; // 피로도 저장
    int check=0;
    
    if(ListSize<=location || picks[0]+picks[1]+picks[2]==0){// 끝까지 가거나 곡괭이를 다쓴 경우
        
        answer=min(answer,sum); //최소 피로도 업데이트
        return;
    }
    
    
    for(int i=location;i<location+5;i++){
        
        if(i>=ListSize){ //마지막 광물 리스트가 5개까지 안되는 경우
            
            break;
        }
        //각 곡괭이로 일을 한 경우
        sumList[0]+=AllList[0][MineralsIntList[i]];
        sumList[1]+=AllList[1][MineralsIntList[i]];
        sumList[2]+=AllList[2][MineralsIntList[i]];  
        
        check=i;
    }
    
    
    
    for(int i=0;i<3;i++){
        if(picks[i]!=0){ //각 곡괭이를 다 안썼다면
            picks[i]-=1; //곡괭이 사용
            dfs(picks,check+1,sum+sumList[i]);
            picks[i]+=1;
        }
    }
    
    
}

int solution(vector<int> picks, vector<string> minerals) {
    
    
    MineralList["diamond"]=0; //단어 처리
    MineralList["iron"]=1;
    MineralList["stone"]=2;
    
    ListSize=minerals.size();

    
    
    for(string i : minerals){
        MineralsIntList.push_back(MineralList[i]);
    }
    
    
    
    dfs(picks,0,0);
    
    
    return answer;
}
