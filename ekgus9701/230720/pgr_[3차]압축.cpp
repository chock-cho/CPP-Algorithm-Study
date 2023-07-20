#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dic;
    string tmp="";
    string w="";
    string c="";
    int add=27; //추가할 곳
    int cur=0; //현재 
    
    for(int i=1;i<=26;i++){ //사전에 등록
        tmp='A'+i-1;
        dic.emplace(tmp,i);
    }
    
    while(true){
        if(cur>msg.size()){
            break;
        }
        
        c=msg[cur];
        if(dic.find(w+c)!=dic.end()){ //w+c가 사전에 있으면
            w=w+c; //현재입력 업데이트
        }
        else{ //사전에 없으면
            answer.push_back(dic.find(w)->second); //색인번호 출력
            dic.emplace(w+c,add++); //다음글자 등록
            w=c; //현재입력 업데이트
        }
        
        cur++;
    }
    
    
    return answer;
}
