class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount + 1, -1);
        count[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && count[i - coins[j]] != -1){
                    if(count[i] == -1 || count[i] > count[i - coins[j]] + 1){
                        count[i] = count[i - coins[j]] + 1;
                    }
                }
            }
        }
        
        return count[amount];
    }
};