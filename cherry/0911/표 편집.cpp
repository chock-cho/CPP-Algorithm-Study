#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

/*
<문제설명>
명령어 기반으로 표의 행을 선택, 삭제, 복구하는 프로그램

- 한 번에 한 행만 선택할 수 있음
- "U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.

- "D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.

- "C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 
    단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.

- "Z" (복구): 가장 최근에 삭제된 행을 원래대로 복구합니다. 
    단, 현재 선택된 행은 바뀌지 않습니다.

입력 : 행개수 n , 처음 선택된 행위치 k, 명령어들이 담긴 배열 cmd 
출력 : 삭제되지 않은 행은 O, 삭제된 행은 X로 표시 -> 문자열 형태로 return 

*/

/*
vector 이용하면 삽입 삭제시, 다른 원소를 움직여 그 빈공간을 채움 -> 불리
set 사용

삭제시 set 에서 현재 iterator 위치의 원소 삭제 -> 그 원소를 deleted stack 에 넣어줌 
복원 원할시 deleted stack 에서 꺼내 set에 다시 insert   

set 특성상 iterator 가 end() 인 경우에 (마지막 원소를 삭제한 경우)에는 
    end() 는 마지막 원소의 한 칸 뒤를 가리키기 때문에 iterator를 한 칸 앞(--)으로 옮겨줘야 함

*/

stack<int> deleted;
set<int> table; 

string solution(int row, int selected, vector<string> cmd) {
    string answer = "";

    for(int i=0;i<row;i++){
        table.insert(i);
        answer+='X';
    }

    auto it = table.begin();
    
    while(selected--) it++; // 선택된 행으로 iterator 옮기기

    for(auto c : cmd){
        char request = c[0];
        int num;
        if(c.size()>1) num = stoi(c.substr(2)); // 횟수까지 같이 요청된 경우

        // 현재 선택된 행에서 X칸 위에 있는 행을 선택
        if(request=='U') while(num--) it--;

        // 현재 선택된 행에서 X칸 아래에 있는 행을 선택
        else if(request=='D') while(num--) it++;

        // 가장 최근에 삭제된 행을 원래대로 복구 -> 현재 선택행에는 변화 없음
        else if(request=='Z'){

            table.insert(deleted.top()); // stack에서 꺼내 insert 
            deleted.pop(); // 지웠던 기록 삭제

        }

        // 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택
        else if(request=='C'){

            deleted.push(*it); // 삭제
            it = table.erase(it);
            if(it==table.end()) it--;
        }
    }

    // 변화여부 갱신
    for(auto v : table) answer[v] = 'O';

    return answer;
}
