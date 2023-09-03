#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int start=0;
    
    for(int i=0;i<number.size()-k;i++){
        char maxNum=number[start];
        int maxIdx=start;
        
        for(int j=start;j<=k+i;j++){ //뒤에 더 큰 숫자가 있을 수 있기때문에 k+i까지 돌기
            if(maxNum<number[j]){ //크면 업데이트
              maxNum = number[j];
              maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum; //가장 큰 수 넣기
    }
    return answer;
}
