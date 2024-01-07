/* Valid Palindrome - 투 포인터 방식으로 풀이해보았습니다. */
// 기존 풀이 방식이 계속 시간 초과가 나서, 투 포인터 방식으로 풀이해보았습니다.
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int en = s.size()-1;
        while(st <= en){
            if(!isalnum(s[st])) {
                st++; continue;
            }
            if(!isalnum(s[en])){
                en--; continue;
            }
            if(tolower(s[st])!=tolower(s[en])) return false;
            else {
                st++; en--;
            }
        }
        return true;
    }
};
