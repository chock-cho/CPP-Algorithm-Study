#include <string>
#include <vector>

using namespace std;
bool isSkip(char c, string skip){
    for(int i = 0; i < skip.size(); i++) {
        if(c==skip[i]){
            return true;
        }
    }
    return false;
}
string solution(string s, string skip, int index) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        for(int j = 0; j < index;){
            c += 1;
            if(c > 'z'){
                c = 'a';
            }
            if(isSkip(c, skip)){
                continue;
            }
            j++;
        }
        answer += c;
    }
    return answer;
}
