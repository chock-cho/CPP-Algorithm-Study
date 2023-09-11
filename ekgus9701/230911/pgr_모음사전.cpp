#include <string>
#include <vector>
#include<iostream>

using namespace std;

string aeiou="AEIOU";
string target="";
int answer=0;
int cnt=0;

void dfs(string word){
    
    if(word==target){ //단어와 목표가 같으면
        answer=cnt;
        return;
    }
    if(word.length()>=5){ //단어의 길이가 5이상이면 더 진행되면 안됨
        return;
    }
    
    for(int i=0;i<aeiou.size();i++){
        cnt++;
        //재귀로 a-> aa-> aaa-> aaaa-> aaaaa 후 
        //for문으로 인해 aaaae -> aaaai ... 로 진행됨
        dfs(word+(aeiou[i])); 
    }
    
}

int solution(string word) {
    
    target=word;
    
    dfs("");
   
    return answer;
}
