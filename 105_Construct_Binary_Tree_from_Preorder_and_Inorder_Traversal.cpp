Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) return NULL;
    return build(0,0,inorder.size()-1,preorder,inorder);
}
TreeNode* build(int preStart,int InStart,int InEnd,vector<int>& preorder, vector<int>& inorder){
    if (InStart > InEnd ) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int index = 0;
    for (int i = InStart; i <= InEnd; ++i){
        if (inorder[i] == root->val){
            index = i;
            break;
        }
    }
    root->left = build(preStart+1,InStart,index-1,preorder,inorder);
    root->right = build(preStart+index-InStart+1,index+1,InEnd,preorder,inorder);
    return root;
}
