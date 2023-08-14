#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
<문제설명>
입력 : 두 문자열 s,skip, 자연수 index
출력 : 알맞게 변경된 암호

내용
1. 문자열 s의 각 알파벳 index 만큼 뒤의 알파벳으로 바꿔줌.
2. index 만큼의 뒤의 알파벳이 z를 넘어갈 경우 다시 a로 돌아감.
3. skip 에 있는 알파벳은 제외하고 건너뜀

*/

string solution(string s, string skip_, int index) {
    string answer = "";

    vector<char> skip(skip_.begin(),skip_.end()); 
    
    // alphabet vector 선언 및 초기화
    vector<char> alphabet;
    for(int i=97;i<=122;i++) alphabet.push_back((char)i);

    // skip에 포함된 원소 지우기
    for(char c : skip) alphabet.erase(remove(alphabet.begin(),alphabet.end(),c),alphabet.end());

    for(char c : s) {
        
        // 주어진 알파벳 idx 찾기
        int cur = find(alphabet.begin(),alphabet.end(),c)-alphabet.begin(); 

        // 규칙에 맞게 변경된 암호 answer에 추가
        answer += alphabet[(cur+index)%alphabet.size()];
        
    }

    return answer;
}
