#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> arr;
    long long ar;
    arr.push_back(1); //0
    arr.push_back(1); //1
    
    for(int i = 2 ; i<n+1 ; i++) {
        ar = (arr[i-2] + arr[i-1]) % 1234567 ;
        arr.push_back(ar);
    }
    answer = arr[n];
    return answer;
}
