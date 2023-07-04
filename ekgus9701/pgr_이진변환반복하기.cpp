#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zeroRemove=0;
    int cnt=0;
    string tempS;
    while(true){
        if(s=="1"){
            break;
        }
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                zeroRemove++;
                s.erase(s.begin()+i);
                i--;
            }
        }
        
        int size=s.size();
        tempS=toBinary(size);
        s=tempS;
        cnt++;
        
    }
    answer.push_back(cnt);
    answer.push_back(zeroRemove);
    return answer;
}
