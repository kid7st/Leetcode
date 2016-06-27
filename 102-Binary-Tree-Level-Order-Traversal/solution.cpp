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
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);    
    }
    
public:
    vector<vector<int>> bfs(TreeNode* root){
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode *> *nodeQueue = new queue<TreeNode *>;
        int depth = 0;
        nodeQueue->push(root);
        while(!nodeQueue->empty()){
            res.push_back(vector<int>{});
            queue<TreeNode *> *newLayer = new queue<TreeNode *>;
            while(!nodeQueue->empty()){
                TreeNode* p = nodeQueue->front();
                nodeQueue->pop();
                res[depth].push_back(p->val);
                
                if(p->left) newLayer->push(p->left);
                if(p->right) newLayer->push(p->right);
            }
            delete nodeQueue;
            nodeQueue = newLayer;
            depth += 1;
        }
        return res;
    }
};