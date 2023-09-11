#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int val = -1;
    int prev = -1;
    int next = -1;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    struct Node node[n];
    stack<Node> deleted;
    
    for(int i = 0; i < n; i++){
        answer += "O";  //O로 초기화
        
        node[i].val = i;
        
        if(i > 0){ //i가 0보다 크면 prev를 연결
            node[i].prev = i - 1;
        }
        
        if(i < n - 1){  //i가 n-1보다 작으면 next를 연결
            node[i].next = i + 1;
        }
    }
    
    for(int i = 0; i < cmd.size(); i++){
        string command = cmd[i];
        
        switch(command[0]){
            case 'U':{
                int move = stoi(command.substr(2));
                
                while(move--){ //숫자만큼 prev로 이동
                    k = node[k].prev;
                }
                
                break;
            }
                
            case 'D':{
                int move = stoi(command.substr(2));
                
                while(move--){ //숫자만큼 next로 이동
                    k = node[k].next;
                }
                
                break;
            }
                
            case 'C':{
                int next = node[k].next;
                int prev = node[k].prev;
                
                deleted.push(node[k]); //삭제한 노드 deleted에 넣기

                
                if(prev > -1){ //맨 앞의 노드가 아니었다면
                    node[prev].next = next; //앞의 노드의 next에 next를 연결
                }
                
                if(next > -1){ //맨 뒤의 노드가 아니었다면
                    node[next].prev = prev; //뒤의 노드의 prev에 prev를 연결
                }
                
                k = next > -1 ? next : prev; //삭제된 행이 가장 마지막행이 아니라면 k=next
                
                break;
            }
                
            case 'Z':{
                Node restore = deleted.top();
                
                int val = restore.val;
                int next = restore.next;
                int prev = restore.prev;
                
                if(prev > -1){ //restore이 맨 앞의 노드가 아니었으면 앞의 노드와 연결
                    node[prev].next = val;
                }
                
                if(next > -1){//restore이 맨 뒤의 노드가 아니었으면 뒤의 노드와 연결
                    node[next].prev = val;
                }
                
                deleted.pop();
                
                break;
            }
        }
    }
    
    while(!deleted.empty()){ //스택이 빌 때까지
        int top = deleted.top().val;
        
        deleted.pop();
        
        answer[top] = 'X';//삭제된 것들을 X로 표시
    }
    
    return answer;
}
