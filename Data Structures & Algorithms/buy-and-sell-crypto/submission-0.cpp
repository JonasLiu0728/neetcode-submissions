class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long pre_min = INT_MAX;
        int max_profit = 0;
        for(int i=0;i<prices.size();i++){
            if( prices[i] - pre_min > max_profit ) max_profit = prices[i] - pre_min;
            if( prices[i] < pre_min ) pre_min = prices[i];
        }
        return max_profit;
    }
};