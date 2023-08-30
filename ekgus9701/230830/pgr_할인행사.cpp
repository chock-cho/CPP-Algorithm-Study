#include <string>
#include <vector>
#include<map>

using namespace std;

map<string,int> wantMap;

int check(map<string,int> m){
    
    for(auto a:wantMap){
        if(m.find(a.first)==m.end()){ //원하는 품목이 없다면
            return 0;
        }
        else if(m[a.first]!=a.second){ //원하는 품목이 원하는 수량만큼 없다면
            return 0;
        }
    }
    
    return 1;
    
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0;i<want.size();i++){
        wantMap[want[i]]=number[i]; //want와 number을 합침
    }
    
    for(int i=0;i<=discount.size()-10;i++){
        map<string,int> m;
        
        for(int j=i;j<i+10;j++){ //10개씩 잘라서 체크
            m[discount[j]]++;
        }
        
        answer+=check(m);
        m.clear();
    }
    return answer;
}
