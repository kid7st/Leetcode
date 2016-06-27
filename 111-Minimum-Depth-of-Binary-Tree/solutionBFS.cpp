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
    int minDepth(TreeNode* root) {
        return bfs(root);
    }
    
private:
    int bfs(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> nodeQueue;
        queue<int> depthQueue;
        int minDepth = INT_MAX;
        nodeQueue.push(root);
        depthQueue.push(1);
        while(!nodeQueue.empty()){
            TreeNode* p = nodeQueue.front();
            nodeQueue.pop();
            int depth = depthQueue.front();
            depthQueue.pop();
            
            if(p->left == NULL && p->right == NULL){
                minDepth = min(minDepth, depth);
                break;
            }else{
                if(p->left != NULL){
                    nodeQueue.push(p->left);
                    depthQueue.push(depth + 1);
                }
                if(p->right != NULL){
                    nodeQueue.push(p->right);
                    depthQueue.push(depth + 1);
                }
            }
        }
        return minDepth;
    }
};