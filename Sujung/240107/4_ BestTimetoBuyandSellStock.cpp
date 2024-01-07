/*  Best Time to Buy and Sell Stock - 문제 설계 필요 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0]; // 구매한 날짜 시점
        // profit = sell - buy(s.t. sell > buy)
        int max_profit = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy) buy = prices[i];
            else {
                max_profit = max(max_profit, prices[i]-buy);
            }
        }
        return max_profit;
    }
};
