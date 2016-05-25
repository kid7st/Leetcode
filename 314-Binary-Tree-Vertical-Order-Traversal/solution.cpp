/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>>();
        
        vector<vector<int>> res;
        map<int, vector<int>> mp;
        
        bfs(root, mp, 0);
        
        for(auto item : mp){
            res.push_back(item.second);
        }
        
        return res;
    }
private:
    void bfs(TreeNode* root, map<int, vector<int>>& mp, int offset){
        queue<pair<TreeNode*, int>> bfsQueue;
        bfsQueue.push(pair<TreeNode*, int>(root, offset));
        while(!bfsQueue.empty()){
            pair<TreeNode*, int> pair_node = bfsQueue.front();
            bfsQueue.pop();
            TreeNode* node = pair_node.first;
            int index = pair_node.second;
            mp[index].push_back(node->val);
            if(node->left != NULL)
                bfsQueue.push(pair<TreeNode*, int>(node->left, index - 1));
            if(node->right != NULL)
                bfsQueue.push(pair<TreeNode*, int>(node->right, index + 1));
        }
    }
};