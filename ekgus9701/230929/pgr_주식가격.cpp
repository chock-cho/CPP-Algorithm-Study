#include <string>
#include <vector>
#include<stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
   for(int i=0;i<prices.size();i++){
       int cnt=1;
       if(i==prices.size()-1){ //마지막 원소인 경우
           answer.push_back(0);
       }
       for(int j=i+1;j<prices.size();j++){
           if(prices[i]>prices[j]){ //가격이 떨어진 경우
               answer.push_back(cnt);
               break;
           }
           else if(j==prices.size()-1){ //가격이 끝까지 떨어지지 않은 경우
               answer.push_back(cnt);
               
           }
           else{
               cnt++;
           }
       }
   }
    
    return answer;
}
