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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack; //record the parent node during the traversal
    
        TreeNode* p = root;
        while(p != NULL || !nodeStack.empty()){
            if(p != NULL){
                nodeStack.push(p);
                p = p->left;    //continue to traversal left
            }else{
                p = nodeStack.top();    //come back to parent (inorder)
                nodeStack.pop();    
                res.push_back(p->val);  
                p = p->right;   //traverse the right child node
            }
        }
        
        return res;
    }
    
};