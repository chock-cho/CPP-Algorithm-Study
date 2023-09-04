/*   이모티콘 할인행사   */
/*
  # 1 할인율 설정:= 중복조합 dfs 이용
  # 2 우선순위 설정 := 정렬 개념( code style : 예외처리 먼저 해줌 )
*/

#include <string>
#include <vector>

using namespace std;
const int MAX = 2E9;
int ansJoinPlus = 0;    // 최댓값(우선순위 높음)
int ansProfit = 0;      // 최댓값(우선순위 낮음)

void calc(vector<int> &sale_rates, vector<vector<int>> &users, vector<int> &emoticons){
    int joinPlus = 0;   // 이모티콘 플러스 가입자 수
    int profit = 0;     // 이모티콘 판매액
    
    for(vector<int> v: users){
        int tmp  = 0;   // 비용 계산 변수
        for(int i = 0; i < sale_rates.size(); i++){
            if(sale_rates[i] < v[0]){
                // 해당 유저가 설정한 할인율 기준치보다 현재 적용되는 할인율이 낮으면
                continue;
                // 구매하지 않는다.
            }
            // 할인율이 높으면
            tmp += (emoticons[i] / 100) * (100 - sale_rates[i]);
            // 해당 이모티콘을 구매한다.(총 금액이 늘어남.)
        }
        
        if(tmp >= v[1]) {
            // 해당 유저가 설정한 총 금액 기준치보다 현재 드는 총 금액이 더 높다면
            joinPlus++; // 이모티콘 플러스에 가입한다.
        }
        else {
            profit += tmp;  // 금액이 늘어난다.
        }
    }
    
        // 제시된 우선순위 순서대로 최선의 값을 갱신해준다.
        if(ansJoinPlus > joinPlus) {
            return;
        }
        
        if(ansJoinPlus == joinPlus && ansProfit >= profit) {
            return;
        }
        
        ansJoinPlus = joinPlus;
        ansProfit = profit;
    
}

/*  세일 금액 조합 구현 := 중복조합, DFS 함수 이용  */
void DFS(vector<int> sale_rates, vector<vector<int>> &users, vector<int> &emoticons){
    if(sale_rates.size() == emoticons.size()){
        calc(sale_rates, users, emoticons);
        return;
    }
    
    for(int i = 10; i <= 40; i += 10){
        // {10, 10, 10, 10} ~ {40, 40, 40, 40} 까지 할인율 설정
        sale_rates.push_back(i);
        DFS(sale_rates, users, emoticons);
        sale_rates.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> v;
    
    DFS(v, users, emoticons);  
    
    vector<int> answer;
    answer.push_back(ansJoinPlus);
    answer.push_back(ansProfit);
    return answer;
}
