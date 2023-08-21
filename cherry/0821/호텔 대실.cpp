#include <string>
#include <vector>

using namespace std;
/*
<문제설명>
입력 : 예약 시간이 문자열 형태로 담긴 2차원 배열 book_time
출력 : 최소 객실의 수 return 
내용 
- 최소한의 객실만을 사용하여 예약 손님을 받으려고 함. 
- 한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소

입실, 퇴실 시간을 단순 정수로 받아들이면 됨
처음엔 정렬 생각 
*/

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int room[2410] = {0,};
    int client = book_time.size(); // 예약한 사람 수

    for(int i=0;i<client;i++){
        
        int start = stoi(book_time[i][0].substr(0,2))*100 + stoi(book_time[i][0].substr(3)); 
        int end = stoi(book_time[i][1].substr(0,2))*100 + stoi(book_time[i][1].substr(3))+10; // 청소시간 추가

        // 10분 추가시 분단위 초과될 경우
        if(end%100>=60) end+=40; // 22:55 + 10 -> 22:65 => +40 -> 23:05
        
        for(int j=start;j<end;j++) room[j]++; // 그 시간대에 room 개수 증가
    }

    for(int i=0;i<2400;i++) answer = max(answer,room[i]);
    
    return answer;
}
