class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> lastDp(3, 0);
        for(int i = 0; i < costs.size(); i++){
            vector<int> dp(3, INT_MAX);
            for(int j = 0; j < costs[i].size(); j++){
                for(int t = 0; t < costs[i].size(); t++){
                    if(j != t){
                        dp[j] = min(lastDp[t] + costs[i][j], dp[j]);
                    }
                }
            }
            lastDp = dp;
        }
        return min(lastDp[0], min(lastDp[1], lastDp[2]));
    }
};