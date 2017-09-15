bool isBalanced(TreeNode* Node){
   if (Node == NULL) return 1;
   int leftHeight = maxHeight(Node->left);
   int rightHeight = maxHeight(Node->right);
   if (abs(leftHeight,rightHeight) <= 1 && isBalanced(Node->left) && isBalanced(Node->right)) return true;
   return false;
}

maxHeight(TreeNode *Node){
  if (Node == NULL) return 0;
  return 1+max(maxHeight(Node->left),maxHeight(Node->right));
}
