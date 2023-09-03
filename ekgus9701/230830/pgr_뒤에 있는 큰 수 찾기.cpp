#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    stack<int> maxes; //뒤에있는 숫자 저장 배열
    
    st.push(-1); //맨 마지막 -1 넣기
    maxes.push(numbers[numbers.size()-1]);
    
    for(int i=numbers.size()-2;i>=0;i--){
        if(maxes.top()>numbers[i]){ //만약 뒤에있는 숫자들 중 가장 가까이 있는 수가 크면
            st.push(maxes.top()); //push
            maxes.push(numbers[i]); //뒤에있는 숫자저장배열에 현재 수 추가
        }
        else{ //가장 가까이 있는 수가 크지 않으면
            while(true){
                maxes.pop(); //스택에서 그 수를 뺌
                if(maxes.empty()){ //스택이 비어있으면
                    st.push(-1); 
                    maxes.push(numbers[i]); //현재 수 넣기
                    break;
                }
                else if(maxes.top()>numbers[i]){ //스택의 가장 위에 있는 수가 현재 수보다 크다면
                    st.push(maxes.top());
                    maxes.push(numbers[i]);
                    break;
                }
            }
        }
    }
    
   while(true){
        if(st.empty()){
            break;
        }
        answer.push_back(st.top());
        st.pop();
    }

    return answer;
}
