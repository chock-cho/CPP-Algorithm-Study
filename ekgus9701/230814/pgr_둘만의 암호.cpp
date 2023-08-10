#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> alp;
    
    for(int i=0;i<26;i++){
        if(skip.find('a'+i)!=string::npos){ //skip문자이면
            continue; //push하지않음
        }
        alp.push_back(int('a')+i); //alp에 push
    }
    
    for(int i=0;i<s.size();i++){
        for(int j=0;j<alp.size();j++){
            if(s[i]==(char)alp[j]){ //s의 문자와 alp안에있는 문자가 같으면
                if(j+index>=alp.size()){ //index만큼의 뒤의 알파벳이 z를 넘어갈 경우
                    answer+=(char)alp[(j+index)%alp.size()]; //다시 a로 돌아가게하고 더해줌
                }
                else{
                    answer+=(char)alp[j+index]; //그냥 더해줌
                }
                
            }
        }
    }

    return answer;
}
