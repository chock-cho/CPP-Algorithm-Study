#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;
int visited[100]={0};
int maxNum=-1;

int solve(int i, vector<int> &cards,int cnt){
    
    if(!visited[i]){ //방문하지않았다면
        
        visited[i]=1;//방문처리
        cnt++;
        maxNum=max(maxNum,cnt); //가장 재귀가 많이 돌았을 때의 수를 구해야해서
        solve(cards[i]-1,cards,cnt);
        
    }
    return maxNum;
    
}

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<int> ans;
    
    for(int i=0;i<cards.size();i++){
        maxNum=-1; //초기화
        int tmp=solve(i,cards,0);//재귀
        
        if(tmp!=-1){ //이미 연 상자들은 넣지 않기 위해서
            ans.push_back(solve(i,cards,0));
        }
        
    }
    
    sort(ans.rbegin(),ans.rend());
    //그룹이 한개라면 최고점수가 0, 그 이상이라면 가장 큰 것 2개 곱하기
    answer=ans.size()==1?0:ans[0]*ans[1]; 
    
    return answer;
}
