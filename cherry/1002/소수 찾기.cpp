#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

/*
입력 : 숫자가 적힌 문자열 numbers , 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 
출력 : 몇개인지 return 

= 내용
- 한자리 숫자가 적힌 종이 조각이 흩어져있음
- 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 함 

= 입출력예시
"17" -> 7,17,71
"011" -> 11,101

*/


// 소수임을 판별하는 함수
bool isPrime(int num){

    if(num<2)return false;

    int a = sqrt(num);
    for(int i=2;i<=a;i++) if(num%i==0) return false;

    return true;
}

int solution(string numbers) {
     
    set<int> cases;
    int answer = 0;

    sort(numbers.begin(),numbers.end());

    // 가능한 모든 조합 만들기 (set에 insert해서 중복된 값 생기지 않도록 )
    do{
        string tmp = "";
        for(int i=0;i<numbers.size();i++){
            tmp.push_back(numbers[i]);
            cases.insert(stoi(tmp));
        }
    } while(next_permutation(numbers.begin(),numbers.end()));
  
    for(auto iter=cases.begin();iter!=cases.end();iter++){
        if(isPrime((long long)*iter)) answer++;
    }

    return answer;

}
