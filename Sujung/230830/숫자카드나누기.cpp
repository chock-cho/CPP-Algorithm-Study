#include <string>
#include <vector>

using namespace std;

// 조건 만족하는지 체크해주는 함수
bool chk(int gcd, vector<int> arr){
    for(int x : arr){
        if(x % gcd == 0){
            return false;
        }
    }
    return true;
}

int GCD(int a, int b){
    // 최대공약수 구하는 함수
    if(b == 0) {
        return a;
    }
    return GCD(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    for(int i = 1; i < arrayA.size(); i++){
        gcdA = GCD(gcdA, arrayA[i]);    // 각 배열의 최대공약수 구하기
        gcdB = GCD(gcdB, arrayB[i]);
    }
    
    if(chk(gcdA, arrayB)){  // A배열의 최대공약수로 arrayB배열의 모든 요소를 나눌 수 없다면(조건을 만족한다면)
        if(answer < gcdA){
            answer = gcdA;
        }
    }
    if(chk(gcdB, arrayA)){
        if(answer < gcdB){
            answer = gcdB;
        }
    }
    return answer;
}
