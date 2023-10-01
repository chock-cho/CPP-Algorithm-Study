#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool sosu(int num){ //소수인지 여부 판단
   
    if(num<=1) return false;
    for(int i=num-1;i>=2;i--){
        if(num%i==0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> number;
    
    for(int i=0;i<numbers.size();i++){
        v.push_back(numbers[i]);
    }
    
    sort(v.begin(),v.end()); //순열 구하려면 정렬 필수
    
    do{
        string temp="";
        for(int i=0;i<v.size();i++){
            temp+=v[i];
            number.push_back(stoi(temp));
        }
    }while(next_permutation(v.begin(),v.end()));
    
    /*next_permutation
    순열을 구하고 싶은 1-2-3-4의 배열이 있다고 가정을 하면 next_permutation의 함수를 사용하면 
    배열의 값들이 다음 순열인 1-2-4-3로 바뀌고 함수는 true를 반환합니다.
    이런 식으로 끝날 때까지 계속 돈다*/
    
    
    //중복 제거
    sort(number.begin(),number.end());
    number.erase(unique(number.begin(),number.end()),number.end());
    
    for(int i=0;i<number.size();i++){
        if(sosu(number[i])){
            answer++;
        }
    }

    return answer;
}
