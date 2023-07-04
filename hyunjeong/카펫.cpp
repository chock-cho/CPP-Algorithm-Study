#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int br = brown;
    int ye = yellow;
    
    int totalblock = br + ye;
    
    int i=totalblock;
    int n1;
    int n2;
    while(i>=1) {
        if(totalblock%i == 0) {
            n1 = i;
            n2 = totalblock/i;
            
            if((n1-2)*(n2-2) == ye) {
                answer.push_back(n1);
                answer.push_back(n2);
                break;
            }
        }
        i--;
    }
    
    
    return answer;
}
