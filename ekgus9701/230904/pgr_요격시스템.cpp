#include<algorithm>
#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) { //e부분 내림차순 정렬
    if(a[1]==b[1]){
        return a[0]<b[0];
    }
    return a[1]>b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int min=100000010;
    
    
    sort(targets.begin(),targets.end(),cmp);

    for(int i=0;i<targets.size();i++){
        
        if(min>=targets[i][1]){ //min이 타겟의 e보다 크면
            answer++;
            min=targets[i][0]; //min update

            
        }
        else{ //min이 타겟의 e보다 작으면
            if(targets[i][0]>min){ //min이 타겟의 s보다 작으면
                min=targets[i][0]; //min update
            }
        }
    } 
    return answer;
}
