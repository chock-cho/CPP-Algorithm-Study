#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
<문제설명>
입력 : 같은 개수의 숫자카드 배열 arrayA, arrayB
출력 : 가장 큰 양의 정수 a / 조건을 만족하는 a가 없다면 return 0

내용

조건 1. 철수가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고 영희가 가진 카드들에 적힌 모든 숫자들 중 
        하나도 나눌 수 없는 양의 정수 a

조건 2. 영희가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고, 철수가 가진 카드들에 적힌 모든 숫자들 중
        하나도 나눌 수 없는 양의 정수 a

*/


// array 카드는 나눌 수 있고, compare 카드는 나눌 수 없는 value 찾기
int findValue(vector<int> &array, vector<int> &compare){

    // array의 최솟값
    int gcdValue = array[0];

    // array 카드 모두를 나눌 수 있는 gcd 찾기
    for(int i=1;i<array.size();i++){
        gcdValue = gcd(gcdValue,array[i]);
        if(gcdValue == 1) return 0;
    }

    // compare 카드를 나눌 수 있다면 out
    for(auto val:compare){
        if(val%gcdValue==0) return 0;
    }

    return gcdValue;

}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    // 정렬
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());

    // 각 배열기준 조건에 맞는 정수값 중 max 값 return 
    return max(findValue(arrayA,arrayB),findValue(arrayB,arrayA));
}
