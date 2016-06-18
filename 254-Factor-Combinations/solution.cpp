class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> acc;
        dfs(n, 2, acc, res);
        return res;
    }
    
private:
    void dfs(int n, int start, vector<int> acc, vector<vector<int>> &res){
        if(acc.size() >= 1){
            acc.push_back(n);
            res.push_back(acc);
            acc.pop_back();
        }
        
        for(; start*start <= n; start++){
            if(n % start == 0){
                acc.push_back(start);
                dfs(n / start, start, acc, res);
                acc.pop_back();
            }
        }
    }
};