#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> answer;


int cnt =0;
 vector<string> split(const string &input, char delimiter) {
     
    vector<string> tokens;
    istringstream tokenStream(input);
    string token;

    while (getline(tokenStream, token, delimiter)) {
        
        if(token =="and"){
            continue;
        }
        
        
        tokens.push_back(token);
    }

    return tokens;
}


void dfs(int idx,int applicant,vector<string> infos,vector<string> query ){ 
// idx: 참여 조건, person : 몇번째 사람
    
    if(idx==4){
        
        // 점수만 더 높은지 확인
        if(stoi(query[4])<=stoi(infos[4])){
            cnt++;
            //cout<<"applicant"<<applicant << "통과\n";
        }
        
        
        return;
    }

      //  cout<<"query[idx]"<<query[idx]<<" "<<"infos[idx]"<<infos[idx]<<"\n";
        if(query[idx]=="-" || query[idx]==infos[idx] ){ // 조건 일치시
            dfs(idx+1,applicant,infos,query);
        }
    
    
}


vector<int> solution(vector<string> info, vector<string> query) {
    
    vector<vector<string>> querys;
    // 이차원 배열 토큰 형태로 담기
    vector<vector<string>> infos;
    for(int i=0;i<info.size();i++){
    	vector<string> tokens = split(info[i],' ');
        infos.push_back(tokens);
 
    } 

 
    
    for(int i=0;i<query.size();i++){
        vector<string> tokens = split(query[i],' ');
        querys.push_back(tokens);

    }

    
    for(int i=0;i<querys.size();i++){

        cnt=0;
    	for(int j=0;j<infos.size();j++){ // 각 사람에 대해 조건 테스트
            dfs(0,j,infos[j],querys[i]);
        }
        
        answer.push_back(cnt);
    }
    return answer;
}