Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

My own solution, didn't look at answers yet, should to, in the next time
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int>res;
    stack<int>values;
    if (!root) return result;
    res.push_back(root->val);
    values.push(root->val);
    preorder(values,res,result,root,sum);
    return result;
}
void preorder(stack<int>& values, vector<int>& res, vector<vector<int>>& result, TreeNode* node, int sum){
    if (!node) return;
    if ((node->left == NULL && node->right == NULL) && values.top() == sum) {
        result.push_back(res);
        res.pop_back();
        values.pop();
        return;
    }
    if (node->left){
        values.push(values.top()+node->left->val);
        res.push_back(node->left->val); 
        preorder(values,res,result,node->left,sum);
    }
    if (node->right){
        values.push(values.top()+node->right->val);
        res.push_back(node->right->val); 
        preorder(values,res,result,node->right,sum);            
    }
    res.pop_back();
    values.pop();
}
