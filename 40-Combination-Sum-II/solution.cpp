class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        find(candidates, target, 0, current, res);
        return res;
    }
private:
    void find(vector<int>& candidates, int target, int k, vector<int> &current, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(current);
        }
        
        for(int i = k; i < candidates.size(); i++){
            if(i != k && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] <= target){
                current.push_back(candidates[i]);
                find(candidates, target - candidates[i], i + 1, current, res);
                current.pop_back();
            }
        }
    }
};