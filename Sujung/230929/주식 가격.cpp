//  주식 가격.cpp
        // prices가 가격이 떨어지는 상태를 찾는 문제
        // prices 배열을 앞에서부터 탐색할 때 숫자가 증가하는 순이면 stk에 push를 해주고, 
        // stk.top보다 작은 수가 등장하면 stk.pop()하면서 현재 값과 하나씩 비교해나간다.
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N, 0);
    stack<int> stk;             // 스택에 밀어넣고 값 증가시키기
    //  1 2 3 2 3
    for(int i = 0; i < N; i++){
        // 스택이 비어있지 않고, 스택의 top값 가격이 현재 시점 가격보다 크다면(가격 떨어짐)
        while(!stk.empty() && prices[stk.top()] > prices[i]){
            answer[stk.top()] = i - stk.top();
            // 가격이 떨어짐 = (i-stk.top) 값 대입
            
            stk.pop(); // 값 제거 해주기
        }
        stk.push(i);
    }
    while(!stk.empty()){
        answer[stk.top()] = N - stk.top() -1;
        stk.pop();
    }
    return answer;
}
