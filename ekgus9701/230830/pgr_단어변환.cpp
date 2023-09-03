#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int answer=51;
bool visited[51];

bool check(string a, string b){
    int cnt=0;
    //몇개 다른지 체크
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]){ //다르면
            cnt++;
        }
    }
    
    if(cnt==1){ //한개만 다르면
        return true;
    }
    else{
        return false;
    }
}

void dfs(string begin, string target,vector<string> words, int step){
    //새로 탐색하는 것의 step이 answer보다 크면 탐색할 필요 없음
    if(answer<=step) return; 
    
    if(begin==target){
        answer=min(answer,step);
        return;
    }
    
    for(int i=0;i<words.size();i++){
        
        if(check(begin,words[i]) && !visited[i]){ //하나만 다르고 방문하지않았다면
            visited[i]=true; //방문 처리
            dfs(words[i],target,words,step+1);
            visited[i]=false; //방문표시 해제해서 다른 최소경로의 변환과정 찾을 수 있게 해줌
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    
    dfs(begin,target,words,0);
    
    if(answer==51){
        return 0;
    }
    return answer;
}
