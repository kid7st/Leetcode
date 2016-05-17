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
    int rob(TreeNode* root) {
        vector<TreeNode*> next;
        next.push_back(root);
        robbedCount = 0;
        norobbedCount = 0;
        bfs(next);
        
        if(robbedCount > norobbedCount)
            return robbedCount;
        else
            return norobbedCount;
    }
   
private:
    int robbedCount, norobbedCount;
    
    void bfs(vector<TreeNode*> nodes){
        vector<TreeNode*> next;
        int newRobbedCount = norobbedCount;
        int newNorobbedCount = robbedCount;
        
        for(int i = 0; i < nodes.size(); i++){
            newRobbedCount += nodes[i]->val;
            
            if(nodes[i]->left != NULL){
                next.push_back(nodes[i]->left);
            }
            if(nodes[i]->right != NULL){
                next.push_back(nodes[i]->right);
            }
        }
        
        robbedCount = newRobbedCount;
        norobbedCount = newNorobbedCount;
        
        if(!next.empty()){
            bfs(next);
        }
    }
};