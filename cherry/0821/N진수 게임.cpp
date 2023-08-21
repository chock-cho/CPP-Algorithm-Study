#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
<문제설명>
입력 : 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
출력 : 튜브가 말해야하는 숫자 
내용 : 숫자를 하나씩 끊어서 말함
*/

string n_to_k (long long n,long long k){
    
    string result;

    if(n==0) return "0"; // 이걸 추가 안해서... 시간을 엄청 끌었음

    while(n){
        if(n%k >= 10) {
            char C = 'A' + (n%k-10);
            result+=C;
        }
        else result+=to_string(n%k);
        n/=k;
    }

    reverse(result.begin(),result.end());
    return result;
}

string solution(int n, int t, int member, int pos) {
    
    string answer = ""; 
    
    string temp = ""; // 전체 문자 담을 배열
    
    int num = member*t; // 최대 진행 횟수
    int val=0;

    // n진수로 변환된 string 구하기 
    while(num){
        temp += n_to_k(val,n);
        val++;
        num--;
    }

    // answer 구하기 
    for(int round=0;round<t;round++){
        int idx = (round * member) + (pos-1);
        answer += temp[idx];
    }

    return answer;
}
