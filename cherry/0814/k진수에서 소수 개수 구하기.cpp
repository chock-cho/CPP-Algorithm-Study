#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

/*
<문제설명>
입력 : 정수 n, 정수 k
내용 : 주어진 n을 k진수로 바꿨을 때, 변환된 수 안에 (다시 10진법 되었을 때) 소수가 몇개인지 찾기
출력 : 소수 개수


*/

// 정수 n을 k진수 바꿔주는 함수
string n_to_k (long long n,long long k){
    
    string result;

    while(n){
        result+=to_string(n%k);
        n/=k;
    }

    reverse(result.begin(),result.end());
    return result;
}

// 구분자에 의해 string 분리해주는 함수
vector<string> split(string s, string divide){
    vector<string> v;
    char *c = strtok((char*)s.c_str(),divide.c_str());

    while(c){
        v.push_back(c);
        c = strtok(NULL, divide.c_str());
    }

    return v;
}

// 소수임을 판별하는 함수
bool isPrime(long long num){
    if(num<2)return false;
    long long a = (long long) sqrt(num);

    for(long long i=2;i<=a;i++) if(num%i==0) return false;

    return true;
}


int solution(int n, int k) {
    int answer = 0;

    // 지정된 진법으로 바꾸기
    string changed = n_to_k(n,k);

    // 0을 기준으로 숫자 나누기
    vector<string> temp = split(changed,"0");
    vector<string> substr;
    
    for(string s : temp){
        // k진법에서 소수 판별
        if(isPrime(stoull(s))) substr.push_back(s);
    }

    for(string s : substr){
        // 10진법에서 소수 판별
        if(isPrime(stoull(n_to_k(stoull(s),10)))) answer++;
    }

    return answer;
}
