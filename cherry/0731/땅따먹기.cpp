#include <iostream>
#include <vector>
using namespace std;

/*
입력 : 2차원 정수 배열 land
내용 : 땅따먹기 게임을 하며 얻을 수 있는 최대 점수
출력 : 최대 점수
*/

int solution(vector<vector<int> > land)
{
    int answer = 0;

    // land 배열 각 행을 순회하며 최대 점수를 구함
    for(int i=0;i<land.size()-1;i++){

        // 규칙에 의해 같은 열은 지나지 못함
        land[i+1][0] += max(land[i][1],max(land[i][2],land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2],land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1],land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1],land[i][2]));
    }
    
    // 최댓값 구하기
    answer = max(land[land.size()-1][0],max(land[land.size()-1][1],max(land[land.size()-1][2],land[land.size()-1][3])));
    return answer;
}
