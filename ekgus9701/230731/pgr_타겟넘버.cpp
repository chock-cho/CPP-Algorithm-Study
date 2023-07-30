#include <string>
#include <vector>

using namespace std;
int answer = 0;
void solve(vector<int> numbers, int target, int sum, int index){
    if(index==numbers.size()){
        if(target==sum){ 
            answer++;
        }
        return;
    }
    //재귀 이용
    solve(numbers, target, sum+numbers[index], index+1); //더하기
    solve(numbers, target, sum-numbers[index], index+1); //빼기
}

int solution(vector<int> numbers, int target) {
    
    
    solve(numbers, target, 0,0);
    return answer;
}
