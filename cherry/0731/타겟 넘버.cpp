#include <string>
#include <vector>

using namespace std;

/*
입력 : 정수 배열 numbers, 정수 target
출력 : numbers의 정수들을 더하거나 빼서 target을 만들 수 있는 경우의 수
*/

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int idx){
    
    // 종료조건
    if(idx == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    
    // 재귀
    dfs(numbers,target,sum+numbers[idx],idx+1);
    dfs(numbers,target,sum-numbers[idx],idx+1);
}

int solution(vector<int> numbers, int target) {
    
    // dfs 호출
    dfs(numbers,target,0,0);
    return answer;
}
