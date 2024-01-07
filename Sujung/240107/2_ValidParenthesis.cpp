/* Valid Parenthesis - 스택을 이용하여 풀이하였습니다. */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c: s) {
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            if(c == ')'){
                if(stk.empty() || stk.top()!='(') {
                    return false;
                }
                stk.pop();
            }
            if(c == ']'){
                if(stk.empty() || stk.top()!='[') {
                    return false;
                }
                stk.pop();
            }
             if(c == '}'){
                if(stk.empty() || stk.top()!='{') {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
