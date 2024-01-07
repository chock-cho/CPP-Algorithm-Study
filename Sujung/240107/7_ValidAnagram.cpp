/* Valid Anagram - 카운트 배열 2개 선언하여 풀이하였습니다. */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int cnt1[26] = {0};
        for(int i = 0; i < s.size(); i++){
            cnt1[s[i]-'a']++;
        }
        int cnt2[26] = {0};
        for(int i = 0; i < t.size(); i++) {
            cnt2[t[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};
