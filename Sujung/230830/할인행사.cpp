#include <string>
#include <vector>
#include <map>
using namespace std;

bool chk(vector<string> &discount, map<string, int> wish_list, int idx){
    for(int i = idx; i < idx+10; i++){
        if(!wish_list[discount[i]]){
            return false;
        }
        wish_list[discount[i]]--;
    }
    // 제품 = 수량
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wish_list; // {품목명, 수량}
    for(int i = 0; i <want.size();i++){
        wish_list[want[i]] = number[i];
    }
    int tmp = discount.size()-9;
    for(int i = 0; i < tmp; i++){
        answer += chk(discount, wish_list, i);
    }
    return answer;
}
