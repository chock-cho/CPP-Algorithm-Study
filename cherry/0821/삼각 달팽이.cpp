#include <string>
#include <vector>

using namespace std;

/*
<문제설명>
입력 : 정수 n 
출력 : 첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return

내용
- 밑변, 높이 n 인 삼각형에서 맨위 꼭짓점부터 반시계방향으로 달팽이 채우기
*/


vector<int> solution(int n) {
    vector<int> answer;
    int snail[1001][1001]; // 삼각형 구성 
    
    int row = 0, col = 0, state = 0, num = 1;
    for(int i = 0; i < n; i++){ 
        
        // 왼쪽 변
        if(state == 0){
            for(int j = i; j < n; j++)
                snail[row++][col] = num++;
            row--; col++;
            state = 1; // state 지정
            continue;
        }
        
        // 밑변
        if(state == 1){
            for(int j = i; j < n; j++)
                snail[row][col++] = num++;
            row--; col-=2;
            state = 2;
            continue;
        }
        
        // 오른쪽 빗변 
        if(state == 2){
            for(int j = i; j < n; j++)
                snail[row--][col--] = num++;
            row+=2; col++;
            state = 0;
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(snail[i][j]) answer.push_back(snail[i][j]);

    return answer;
}
