Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int count = 0;
        queue<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            for (int i = 0, n = s.size(); i < n; ++i){
                TreeNode *p = s.front();
                s.pop();
                if (p->left != NULL){
                    s.push(p->left);
                }
                if (p->right != NULL){
                    s.push(p->right);
                }
            }
            count++;
        }
        return count;
    }
    
    
};
