#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 양의 정수 n 을 k 진수로 바꿔주는 함수 
string toBaseK(int n, int k){

    if (n < k ){
        return to_string(n);
    }
    int quotient = (n / k) ; // 몫
    char remaindar = (n % k) +'0'; // 나머지
    
    return toBaseK(quotient,k) + remaindar;
    
}

bool isPrime(long long n){

    if(n==1){
        return false; 
    }
    for(long long i=2;i*i<=n;i++){
        
        if(n%i==0){
            return false;
        }
        
    }
    
    return true; 
}

// 0 의 위치를 마킹하고 그 사이사이에 있는 숫자들이 소수인지 판단
int check(string number){
    
    int cnt =0;

    // 0 이 존재하는 인덱스 마킹
    vector<int> zero;
    
    for(int i=0;i<number.size();i++){
        
        if(number[i]=='0'){
            zero.push_back(i);
        } 
    }
    
    int start = -1;
    int end = 0;
    // start ~ end 까지의 문자열이 소수인지 확인
    for(int i=0;i<zero.size()+1;i++){
        
        if(i!=0){
            start=zero[i-1];
        }
        end = zero[i];
        
    	if(i==zero.size()){
            end=number.size();
            
        }
        
        if((end-start-1)<=0)
            continue;
        
            string sub_str = number.substr(start+1,end-start-1);
                
            if(isPrime(stol(sub_str))){ // 주어진 수가 소수라면
                cnt++;
            }
            
        
        
     
    }
    
    return cnt;
}
/**
[k진수에서 소수 개수 구하기]
https://school.programmers.co.kr/learn/courses/30/lessons/92335

1. 주어진 숫자 n 을 k진수로 바꾼다.
2. 0 사이사이에 있는 숫자들이 소수인지 판단하고 그 개수를 센다.

< 문제 풀 때 주의할 점 >

n 을 k 진수로 바꾸었을 때 최댓값은? 
1,000,000 ~ (3의 12제곱) 이므로 10진법으로 읽는다면 10^12 즉, int 형 범위를 벗어난다.

! 따라서 변환된 수를 저장하는 자료형은 long 같은 더 큰 범위 자료형을 사용해야한다. 
! 이떄 integer overflow ( int * int , int + int ) 에도 유의한다.

! 소수 판단시 2 ~ n 까지 모든 수를 나눠보면서 소수인지 판단하면 시간초과 
=> 2 ~ n 의 제곱근 까지 나눠주기

*/

int solution(int n, int k) {
    int answer = -1;
    
    
    string nToBaseK = toBaseK(n,k);
     
    answer = check(nToBaseK);
    
    
    return answer;
}