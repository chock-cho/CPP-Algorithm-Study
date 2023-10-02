#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i <=sqrt(n); i++){
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    set<int> answer;
    int tmp= 0;
    sort(numbers.begin(), numbers.end());
    do {
        for(int i = 1; i <= numbers.size(); i++){
            
            tmp = stoi(numbers.substr(0,i));
            if(isPrime(tmp)){
                answer.insert(tmp);
            }
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    return answer.size();
}
