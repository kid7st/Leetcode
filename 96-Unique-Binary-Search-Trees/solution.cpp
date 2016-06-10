class Solution {
public:
    int numTrees(int n) {
        vector<int> unique(n + 1, 0);
        unique[0] = 1;
        unique[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                unique[i] += unique[j] * unique[i - 1 - j];
            }
        }
        
        return unique[n];
    }
};