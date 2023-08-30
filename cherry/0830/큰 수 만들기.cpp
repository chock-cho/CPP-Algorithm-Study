#include <string>
#include <vector>

using namespace std;

/*
입력 : 숫자 number, 제거할 수의 개수 k
출력 : k개의 수를 제거했을 때 만들 수 있는 가장 큰 숫자 (문자열의 순서는 유지해야 함)
*/

int cursor=0;

void erase(string &number){
    
    
    // 작은 경우 or cursor가 맨 마지막까지 간 경우
    if(number[cursor] < number[cursor+1] || cursor == number.length()-1) {
        number.erase(number.begin()+cursor);
        cursor=0;
        return;
    }

    // 같거나 큰 경우 cursor 이동
    else {
        ++cursor;
        erase(number);
    }

}

string solution(string number, int k) {
    
    while(k--) erase(number);
    
    return number;
}
