Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<vector<int>> rres;
        if (root == NULL) return res;
        q.push(root);
        while(q.size()!=0){
            vector<int> tmp;
            cout << q.size() << endl;
            int n = q.size();
            for (int i = 0; i < n; ++i){
                TreeNode *temp = q.front();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
                tmp.push_back(temp->val);
                q.pop();
            }
            res.push_back(tmp);
        }
        reverse(res,&rres);
        for (auto a = rres.begin(); a != rres.end(); ++a){
            for (auto b = (*a).begin(); b != (*a).end(); ++b){
                cout << *b << endl;
            }
        }
        return rres;
    }
    vector<vector<int>> reverse(vector<vector<int>> heights, vector<vector<int>>* res){
        for (vector<vector<int>>::reverse_iterator it = heights.rbegin(); it != heights.rend(); ++it){
            (*res).push_back(*it);
        }
        return *res;
    }
};
