Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


Three different ways, should look at the discuss:
DFS:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int count = counter(root->left);
        if (count >= k){
            return kthSmallest(root->left,k);
        }else if(k > count+1){
            return kthSmallest(root->right,k-count-1);
        }else{
            return root->val;
        }
    }
    int counter(TreeNode* root){
        if (!root) return 0;
        return 1+counter(root->left)+counter(root->right);
    }
    
    
iterative BFS:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int i = 0;
        stack<TreeNode*>s;
        TreeNode* move = root;
        s.push(move);
        move = move->left;
        while(i != k){
            while(move){
                s.push(move);
                move = move->left;
            }
            move = s.top();
            s.pop();
            i++;
            if (i == k) break;
            move = move->right;
        }
        return move ? move->val : 0;
    }
    
recursive BFS:
public:
    int result;
    int count;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        count = k;
        helper(root);
        return result;
    }
    void helper(TreeNode* root){
        if (!root) return;
        helper(root->left);
        if (count == 1) {
            result = root->val;
        }
        count--;
        helper(root->right);
    }
