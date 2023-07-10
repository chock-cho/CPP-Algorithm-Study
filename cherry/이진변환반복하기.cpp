#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int cnt=0; int zeros=0;
    
    while(true){
        int val=0;
        for(char c:s){
            if(c=='1') val++; // 1의 개수이자 제거된 후 길이
            else zeros++; // 제거된 0개수 
        }
        
        // 이진변환 (원래는 reverse 해줘야하지만 개수만 구하면 되기 때문에 상관없음)
        s="";
        while(val>0){
            if(val%2==0) s+="0";
            else s+="1";
            val/=2;
        }
        cnt++;
        if(s=="1") break;
    }

    return {cnt,zeros};
}
