#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
<문제설명>
입력 : 정수배열 numbers
출력 : 모든 원소에 대한 뒷 큰 수들을 차례로 담은 배열 / 뒷큰수가 존재하지 않는 원소는 -1
내용 : 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수

처음시도 :  이중for문 -> 시간초과
*/

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer(numbers.size(),-1);

    stack<pair<int,int>> s; // <값, 인덱스>

    for(int i=0;i<numbers.size();i++){

        // numbers[i]가 top보다 크다면
        while(!s.empty() && s.top().first < numbers[i]){
            
            answer[s.top().second] = numbers[i];
            s.pop();

        }
        s.push(make_pair(numbers[i],i));
    }
    return answer;
}
