Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.


Iteratively:
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    queue<TreeNode*> left;
    queue<TreeNode*> right;
    if (root->left != NULL && root->right != NULL){
        left.push(root->left);
        right.push(root->right);
    }else if (root->left == NULL && root->right == NULL){
        return true;
    }else return false;
    return BFS(left,right);
}
bool BFS(queue<TreeNode*>& left, queue<TreeNode*>& right){
    while (left.size() == right.size()){
            int tmp = left.size();
            for (int i = 0; i < tmp; ++i){
                TreeNode *le = left.front();
                left.pop();
                TreeNode *ri = right.front();
                right.pop();
                if (le->val != ri->val) return false;
                else if (le->val == INT_MAX && ri->val == INT_MAX) continue;
                else {
                    if (le->left != NULL) left.push(le->left); else left.push(new TreeNode(INT_MAX));
                    if (le->right != NULL) left.push(le->right); else left.push(new TreeNode(INT_MAX));
                    if (ri->right != NULL) right.push(ri->right); else right.push(new TreeNode(INT_MAX));
                    if (ri->left != NULL) right.push(ri->left); else right.push(new TreeNode(INT_MAX));
                }
            }
        if (left.empty()) return true;
    }
    return false;
}

Recursive:
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return DFS(root->left,root->right);
}
bool DFS(TreeNode* left, TreeNode* right){
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL || left->val != right->val) return false;
    if (left->val == right->val){
        return DFS(left->right, right->left) && DFS(left->left, right->right);
    }
}
