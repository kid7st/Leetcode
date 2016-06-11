class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '1') dp[i][j] = 1;
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                if(matrix[i][j] == '1'){
                    int inside = dp[i - 1][j - 1];
                    bool isOne = true;
                    int k1 = 1;
                    for(;k1 <= inside && matrix[i - k1][j] == '1'; k1++);
                  
                    int k2 = 1;
                    for(;k2 <= inside && matrix[i][j - k2] == '1'; k2++);
                
                    int k = min(k1, k2);
                    dp[i][j] = k;
                }
            }
        }
        
        int maxSquare = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                maxSquare = max(maxSquare, dp[i][j]*dp[i][j]);
            }
        }
        
        return maxSquare;
    }
};