#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*

입력 : 응시자들의 정보, 대기실 구조를 대기실별로 담은 2차원 문자열배열 places 
출력 : "대기실별"로 거리두기를 지키고 있으면 1, 한명이라도 지키지 않고 있으면 0을 배열에 담아 return 

<내용 및 제한사항>

]] 입력 세부사항
- p : 응시자가 앉아있는 자리
- o : 빈 테이블 
- x : 파티션

]] 제한사항
- 응시자들끼리 맨해튼거리가 2 이하로 앉지 말기 
- 응시자가 앉아있는 자리 사이가 파티션으로 막혀 있을 경우에는 허용함 

]] 맨해튼 거리
- |r1-r2| + |c1-c2|

<입출력 예시> 

[["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], 
 ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], 
 ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], 
 ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], 
 ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]] 

 [1, 0, 1, 1, 1] 

<풀이>
처음 접근 : p가 있는 위치를 다 저장해서 
    -> p끼리의 거리가 맨해튼거리가 2이하인 사람 내에 파티션, 빈테이블 여부를 확인 
    -> 계속 오류....
    -> 수정완료

다음 접근 
- p인 지점이 나타났을 때 맨해튼거리 2 이내 조사 

*/

/*
vector<int> answer;

void check(vector<string> &places){

    vector<pair<int,int>> pos;
    vector<vector<int>> waiting_room;

    // 대기실 구성하기
    for(int row=0;row<places.size();row++)
        for(int col=0;col<places[row].size();col++){

            // 파티션 = 1
            if(places[row][col] == 'X'){
                waiting_room[row][col] = 1;
            }

            // 빈테이블 = 0
            else if(places[row][col] == 'O'){
                waiting_room[row][col] = 0;
            }

            // 사람 = 0 , 위치저장
            else if(places[row][col] == 'P') {
                waiting_room[row][col] = 0;
                pos.push_back({row,col});
            }
        }
    
    for(int i=0;i<pos.size()-2;i++) // 기준
        for(int j=i+1;j<pos.size()-1;j++){ // 비교
            if(abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second) <= 2){ // 맨해튼거리 2 이하
                
                int row_min = min(pos[i].first,pos[j].first); int row_max = max(pos[i].first,pos[j].first);
                int col_min = min(pos[i].second,pos[j].second); int col_max = max(pos[i].second,pos[j].second);
                int sum=0;

                for(int r=row_min;r<=row_max;r++){
                    for(int c=col_min;c<=col_max;c++){
                        sum+=waiting_room[r][c];
                    }
                }

                // 파티션 있는 경우 (거리두기 O)
                if (sum!=0) continue;
                
                // 파티션 없는 경우 (거리두기 X)
                else {
                    answer.push_back(0);
                    return;
                }
            }
        }
    
    answer.push_back(1);
    return;

}

vector<int> solution(vector<vector<string>> places) {

    for(int i=0;i<5;i++){
        check(places[i]);
    }

    return answer;
}

*/

vector<pair<int, int>> person;

int check_par(vector<string> room, int r1, int c1, int r2, int c2){
    int min_r = min(r1, r2);
    int min_c = min(c1, c2);
    int max_r = max(r1, r2);
    int max_c = max(c1, c2);
    
    //세로로 나란히
    if(r1 == r2){
        if(room[r1][(c1+c2)/2] == 'X')
            return 1;
    }
    //가로로 나란히
    else if(c1 == c2){
        if(room[(r1+r2)/2][c1] == 'X')
            return 1;
    }
    // '\'모양 대각선
    else if(r2 == max_r && c2 == max_c){
        if(room[max_r-1][max_c] == 'X' && room[max_r][max_c-1] == 'X')
            return 1;
    }
    // '/'모양 대각선
    else if (r2 == max_r && c1 == max_c){
        if(room[min_r][min_c] == 'X' && room[max_r][max_c] == 'X')
            return 1;
    }
    
    
    return 0;   //파티션 안 지켜짐
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int sw=1;   //각 대기실의 거리두기가 잘 지켜지고 있는지
    
    for (int i=0; i<5; i++){
        person.clear();
        
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                //응시자 있는 위치들 벡터에 추가
                if(places[i][j][k] == 'P')
                    person.push_back(make_pair(j, k));;
            }
        }
        
        //응시자간의 거리 확인
        sw = 1;
        for(int j=0; j<person.size(); j++){
            int p1_r = person[j].first;
            int p1_c = person[j].second;
            for(int k=j+1; k<person.size(); k++){
                int dist=0;
                int p2_r = person[k].first;
                int p2_c = person[k].second;
                dist = abs(p1_r - p2_r) + abs(p1_c-p2_c);
                
                //거리 안지켜짐
                if(dist <= 2){
                    //파티션도 없음
                    if(check_par(places[i], p1_r, p1_c, p2_r, p2_c) == 0){
                        sw = 0;
                        break;
                    }
                }
            }
            
            if(sw == 0)
                break;
        }
        answer.push_back(sw);
    }
    
    return answer;
}
