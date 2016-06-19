class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        dfs(n, k, 1, current, res);
        return res;
    }
    
private:
    void dfs(int n, int k, int start, vector<int> &current, vector<vector<int>> &acc){
        if(current.size() == k){
            acc.push_back(current);
            return;
        }
        
        for(int i = start; i <= n; i++){
            current.push_back(i);
            dfs(n, k, i + 1, current, acc);
            current.pop_back();
        }
        
        return;
    }
};