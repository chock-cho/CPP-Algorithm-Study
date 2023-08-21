#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int toInt(string s){
    int hour=stoi(s.substr(0,2));
    int minute=stoi(s.substr(3,2));
    
    return hour*60+minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int cnt=0;
    
    vector<pair<int,int>> time;
    
    for(int i=0;i<book_time.size();i++){
        int start=toInt(book_time[i][0]);
        int end=toInt(book_time[i][1])+10;
        time.push_back({start,1}); //시작하면 회의개수 +1되어야하니까
        time.push_back({end,-1}); //끝나면 회의개수 -1 되어야하니까
        
    }
    
    sort(time.begin(),time.end());
    
    //각 분마다 몇개의 회의가 진행되고있는지 업데이트
    for(int i=0;i<time.size();i++){
       cnt+=time[i].second;
       answer=max(answer,cnt); //동시에 진행되고있는 회의의 최대개수 구하기
    }
    
    
    return answer;
}
