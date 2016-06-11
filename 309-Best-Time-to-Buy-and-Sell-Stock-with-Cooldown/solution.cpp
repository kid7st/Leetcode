class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
            
        int beforeMaxSell = 0;
        int maxSell = 0;
        int maxBuy = 0 - prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            int bpMaxBuy = maxBuy;
            int buyProfit = (i < 2 ? 0 : beforeMaxSell) - prices[i];
            maxBuy = max(maxBuy, buyProfit);
            
            int sellProfit = bpMaxBuy + prices[i];
            beforeMaxSell = maxSell;
            maxSell = max(maxSell, sellProfit);
        }
        
        return maxSell;
    }
};