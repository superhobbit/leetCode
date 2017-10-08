Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

My approach is not very good:
bool isValidBST(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        for (int i = 0; i < q.size(); ++i){
            TreeNode* tmp = q.front();
            q.pop();
            bool res = check_left(tmp->left,tmp->val) && check_right(tmp->right,tmp->val);
            if (!res) return false;
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);                
        }
    }
    return true;
}
bool check_left(TreeNode* root, int val){
    if (!root) return true;
    if (root->val >= val) return false;
    return check_left(root->left, val) && check_left(root->right, val);
}
bool check_right(TreeNode* root, int val){
    if (!root) return true;
    if (root->val <= val) return false;
    return check_right(root->left, val) && check_right(root->right,val);
}

use inorder traverse:
bool isValidBST(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return true;
    stack<TreeNode*>s;
    TreeNode* pre = NULL;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (pre && pre->val >= root->val) return false;
        pre = root;
        root = root->right;
    }
    return true;
}
