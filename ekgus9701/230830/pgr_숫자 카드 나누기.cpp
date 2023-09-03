#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b) { //최대공약수 구하기
    
   if(b==0) return a;
    else return gcd(b,a%b);

}

int findValue(vector<int>& v1, vector<int>& v2, int size) {
        
    int gcdValue = v1[0];
    
    for(int i = 1; i < size; i++) { // array 모든 원소들의 최대공약수 찾기
        gcdValue = gcd(gcdValue, v1[i]);
        
        if(gcdValue == 1) return 0; //최대공약수가 1이라면 -> 나눠지지않는 것임
    }
    
    for(auto v : v2) {
        if(v % gcdValue == 0) //나눠진다면 
            return 0;
    }
    
    return gcdValue;
    
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int size = arrayA.size();
    
    int a = findValue(arrayA, arrayB, size);
    int b = findValue(arrayB, arrayA, size);
    
    return max(a, b);
}
