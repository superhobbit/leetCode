Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    
I use level order, not very good, only beat 31%  
void connect(TreeLinkNode *root) {
  if (root == NULL) return;
  queue<TreeLinkNode*> q;
  q.push(root);
  changeTree(q);
}
void changeTree(queue<TreeLinkNode*> q){
  while(!q.empty()){
      int size = q.size();
      for (int i = 0; i < size; ++i){
          TreeLinkNode* tmp = q.front();
          q.pop();
          if (i == size-1){
              tmp->next = NULL;
          }else{
              tmp->next = q.front();
          }
          if (tmp->left != NULL) q.push(tmp->left);
          if (tmp->right != NULL) q.push(tmp->right);
      }
  }
}
