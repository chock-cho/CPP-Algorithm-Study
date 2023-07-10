#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum=brown+yellow;
    int a,b;
    
    for(int i=sum;i>=1;i--){
        a=i;
        if(sum%a==0){
            b=sum/a;
            
            if(2*a+2*b-4==brown){
                answer.push_back(a);
                answer.push_back(b);
                return answer;
            }
        }
    }
    
    
    return answer;
}
