#include <string>
#include <vector>
#include <set>
#include <cstring>

using namespace std;
int answer = 0;
bool visited[10]={false,};
set<int> s;

bool isPrime(string str) {
    int n = stod(str);
    if (n < 2) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) { // 제곱근까지만 검사
        if (n%i == 0) {
            return false;
        }
    }
    s.insert(n);
    return true;
}

void dfs(string numbers, string str) {

    
    if(str.length()==numbers.size()){
        return;
    }
   
    for (int i = 0; i < numbers.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            string new_str = str + numbers[i];
            isPrime(new_str);
            dfs(numbers,new_str);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {

    dfs(numbers, "");
    answer = s.size();
    return answer;
}