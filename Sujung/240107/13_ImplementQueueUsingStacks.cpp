/* Implement Queue using Stacks - 2개의 스택을 선언하여 풀이하였습니다. */
class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ele = stk2.top();
        stk2.pop();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }
    
    int peek() {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ele = stk2.top();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }
    
    bool empty() {
        return stk1.empty();
    }
};
