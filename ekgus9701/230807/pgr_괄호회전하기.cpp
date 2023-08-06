#include <string>
#include <vector>
#include<iostream>
#include<stack>

using namespace std;


int solution(string s) {
    int ans = 0;

    for(int i=0;i<s.length();i++){ //괄호 하나씩 회전시키기
        stack<char> st;
        bool flag=false;
        for(int j=0;j<s.length();j++){ //올바른 괄호인지 확인하기
            if(s[j]=='{' || s[j]=='(' || s[j]=='['){
                st.push(s[j]);
                flag=true; //한번이라도 {를 push했는지, }])만 있는 경우를 방지하기 위해서
            }
            else{
                if(s[j]=='}' &&st.top()=='{'){
                st.pop();
                }
                if(s[j]==']' &&st.top()=='['){
                    st.pop();
                }
                if(s[j]==')' &&st.top()=='('){
                    st.pop();
                }

            }
        }

        if(st.empty()&&flag){
            ans++;
        }

        //괄호 회전
        char temp=s.front();
        s.erase(s.begin());
        s+=temp;


    }

    return ans;
}

 
