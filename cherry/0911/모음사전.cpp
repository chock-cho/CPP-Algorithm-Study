#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
<문제설명>
입력 : 단어하나 word 가 주어짐 (word 길이 1이상 5이하)
출력 : 단어가 사전에서 몇번째 단어인지 return 

사전 구성 
A E I O U 로만 이루어져 있음
A -> AA -> AAA -> AAAA -> AAAAA -> AAAAE -> AAAAE -> AAAAO -> AAAAU
-> AAAE
*/

string words = "AEIOU";
int answer;
int cnt;
bool conti = true;

void count(string now,string target){

    // target 문자가 되었을 때의 번수 return 
    if(now == target) {
        answer = cnt;
        conti = false;
    }

    if(now.length()>5) return; // word의 길이는 5이하

    // target 문자가 되기 전까지 cnt++
    cnt++;
    cout << now << endl;

    // 사전 순서대로 
    for(int i=0;i<words.length();i++){
        count(now+words[i],target);
        if(conti==false) break;
    }
}

int solution(string word) {
    count("",word);
    cout << answer;
    return answer;
}

int main(){
    solution("AAAE");
}
