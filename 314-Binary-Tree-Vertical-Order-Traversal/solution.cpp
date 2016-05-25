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
            
        int offset = 0;
        TreeNode* node =root->left;
        while(node != NULL){
            offset += 1;
            node = node->left;
        }
        int len = offset + 1;
        node = root->right;
        while(node != NULL){
            len += 1;
            node = node->right;
        }
        
        vector<vector<int>> res(len, vector<int>());
        bfs(root, res, offset);
        return res;
    }
private:
    void bfs(TreeNode* root, vector<vector<int>>& res, int offset){
        queue<pair<TreeNode*, int>> bfsQueue;
        bfsQueue.push(pair<TreeNode*, int>(root, offset));
        while(!bfsQueue.empty()){
            pair<TreeNode*, int> pair_node = bfsQueue.front();
            bfsQueue.pop();
            TreeNode* node = pair_node.first;
            int index = pair_node.second;
            res[index].push_back(node->val);
            if(node->left != NULL)
                bfsQueue.push(pair<TreeNode*, int>(node->left, index - 1));
            if(node->right != NULL)
                bfsQueue.push(pair<TreeNode*, int>(node->right, index + 1));
        }
    }
};