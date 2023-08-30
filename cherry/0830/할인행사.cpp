#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

/*
<문제설명>
입력 : 원하는 제품 문자열 배열 want, 제품의 수량 정수 배열 number, 마트할인제품 문자열 배열 discount
출력 : 정현이가 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수 / 가능한 날 없으면 0 return 

내용
- 10일동안 회원자격 부여, 회원대상 할인 진행
- 할인제품 -> 하루에 하나씩만 구매 가능

처음시도 -> 윈도우처럼 풀이 -> for문과 변수설정이 어려움 -> 테케 몇개 틀림
정현에 대한 map 만 설정 -> mart 것도 만들어서 해결
*/

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> wantMap; // <물건, 원하는 수량>

    // 정현의 map 설정
    for(int i = 0; i < number.size(); i++)
        wantMap.insert({want[i], number[i]});
    

    for(int i = 0; i <= discount.size() - 10; i++){

        // 마트 할인정보에 따른 map 설정
        unordered_map<string, int> martDiscount;
        for(int j = i; j < i + 10; j++){
            martDiscount[discount[j]] += 1;
        }

        // operator 사용해서 map 비교
        if(martDiscount == wantMap)
            answer++;
    }

    return answer;
}
