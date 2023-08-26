#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int width,height,k=brown+yellow;
    
    for(int i=k;i>=1;i--){
       if((k%i==0)&&(i-2)*((k/i)-2)==yellow) {
           width=i; height=k/i; break;
       }
    }
    
    return {width,height};
}
