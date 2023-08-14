#include <string>
#include <vector>

using namespace std;

/*
<문제설명>
입력 : 2차원 행렬 arr1, arr2
출력 : 두 행렬을 곱한 결과 

조건 : 행렬길이 -> 2이상 100이하, 원소 -10이상 20이하

접근자 조정했을 때 오히려 오류 나는 이유???

*/

vector<vector<int>> solution(vector<vector<int>> first, vector<vector<int>> second) {
    
    // 결과가 될 vector의 row col 개수
    int row = first.size(); 
    int col_ = second[0].size();

    // 곱셈시 접근 횟수 (첫 행렬의 열 개수만큼)
    int num = first[0].size();
    
    // answer 행렬 초기화
    vector<vector<int>> answer(row,vector<int> (col_));

    while(row--){ // 첫 vector의 행 기준 연산

        for(int col=0;col<col_;col++){ // 열 옮겨가며 연산
            int result=0;

            // 각 원소 연산
            for(int pos=0;pos<num;pos++){
                result += first[row][pos]*second[pos][col];
            }
            
            answer[row][col] = result;
        }

    }
    
    return answer;
}

