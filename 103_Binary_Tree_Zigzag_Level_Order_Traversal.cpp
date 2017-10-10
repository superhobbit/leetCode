Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>result;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    if (root) s1.push(root);
    while(!s1.empty() || !s2.empty()){
        vector<int> res(0);
        if (!s1.empty()){
            int size = s1.size();
            for (int i = 0; i < size; ++i){
                TreeNode* tmp = s1.top();
                res.push_back(tmp->val);
                s1.pop();
                if (tmp->left) {
                    s2.push(tmp->left);
                }
                if (tmp->right) {
                    s2.push(tmp->right);
                }
            }
        }else {
            int size = s2.size();
            for (int i = 0; i < size; ++i){
                TreeNode* tmp = s2.top();
                res.push_back(tmp->val);
                s2.pop();
                if (tmp->right){
                    s1.push(tmp->right);
                }
                if (tmp->left){
                    s1.push(tmp->left);
                }
            }
        }
        if (res.size()) result.push_back(res);
    }
    return result;
}
