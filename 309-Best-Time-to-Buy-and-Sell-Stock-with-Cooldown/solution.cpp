class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        vector<int> maxSell(prices.size());
        vector<int> maxBuy(prices.size());
        
        maxSell[0] = 0;
        maxBuy[0] = 0 - prices[0];
        for(int i = 1; i < prices.size(); i++){
            int buyProfit = (i < 2 ? 0 : maxSell[i - 2]) - prices[i];
            maxBuy[i] = max(maxBuy[i - 1], buyProfit);
            
            int sellProfit = maxBuy[i - 1] + prices[i];
            maxSell[i] = max(maxSell[i - 1], sellProfit);
        }
        
        return maxSell[prices.size() - 1];
    }
};