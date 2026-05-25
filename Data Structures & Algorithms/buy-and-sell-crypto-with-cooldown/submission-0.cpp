class Solution {
public:
    //每次賣都要休息兩天
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];//買第一個 目前虧錢
        int sell = 0;//剛賣完
        int rest = 0;//沒有剛賣完 也沒有持有股票 自由狀態
        
        for(int i=1;i<prices.size();i++){
            int prev_hold = hold;
            int prev_sell = sell;
            int prev_rest = rest;

            hold = max(prev_hold, prev_rest - prices[i]);
            sell = prev_hold+prices[i];
            rest = max(prev_rest,prev_sell);
        }
        return max(sell, rest);
    }
};