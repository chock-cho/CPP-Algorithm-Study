#include <string>
#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    /*풀이방법
    s를 n으로 나눠서 몫을 n개만큼 list에 넣고 나머지를 n개의 요소에 1씩 나눈다
    n이 3, s가 10라면
    몫이 3, 나머지가 1이므로
    [3,3,3]를 먼저 넣고 나머지 1을 한 요소에 더해 [4,3,3]를 만든다
    그리고 sort
    */
    
    vector<int> answer;
    
    int list[10010]={0};
    
    if(s/n==0){ //나눠지지않으면
        answer.push_back(-1);
        return answer;
    }
    
    for(int i=0;i<n;i++){ //몫을 n개만큼 list에 넣음
        list[i]=s/n;
    }
    
    for(int i=0;i<s%n;i++){ //나머지를 list의 요소에 1씩 나눠서 넣어줌
        list[i]++;
    }

    for(int i=0;i<n;i++){
        answer.push_back(list[i]);
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}
