#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
<문제설명>
입력 : begin 단어, target 단어
출력 : 최소 몇 단계의 과정을 거쳐 begin 을 target으로 변환할 수 있는지 return 
        -> 변환할 수 없는 경우 return 0

내용 : begin 에서 target으로 변환하는 가장 짧은 변환 과정 찾기 
- 1. 한 번에 한 개의 알파벳만 바꿀 수 있음
- 2. words에 있는 단어로만 변환할 수 있음
*/

int answer = 100;

// 시작단어, 목표단어, 단어리스트, 단어리스트사용여부, 목표까지 들어간 횟수(깊이)

void word_transform(string begin, string target, vector<string> words, vector<bool>& isUsed, int cnt = 0) {
    
    // 단어의 사이즈만큼 반복
    for (int i = 0; i < words.size(); i++) {
        
        int diff = 0; // 일치여부
        
        // 일치여부 확인
        for (int j = 0; j < words[i].length(); j++)
            if (!isUsed[i] && begin[j] != words[i][j]) diff++;

        // 한 글자만 다른경우
        if (diff == 1) {
            
            // target 단어와 같은 경우 answer 값 갱신
            if (target == words[i] && answer > cnt + 1) { 
                answer = cnt + 1;
                return;
            }

            isUsed[i] = true; // 단어 사용

            word_transform(words[i], target, words, isUsed, cnt + 1);
            
            // 함수를 나온경우 단어사용여부 해제
            isUsed[i] = false;
        }
    }
}
 
int solution(string begin, string target, vector<string> words) {

    vector<bool> isUsed(words.size(), false); // 사용된 매개 words check

    word_transform(begin, target, words, isUsed);
   
    if (answer == 100)  return 0; // answer 값이 갱신되지 않은 경우 -> 방법 x
    
    return answer;
}
