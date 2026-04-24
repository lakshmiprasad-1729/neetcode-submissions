/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,int ind,vector<vector<int>>& ans){
        if(root==nullptr) return;
        int n = ans.size();
        if(ind < n) ans[ind].push_back(root->val);
        else ans.push_back({root->val});
        solve(root->left,ind+1,ans);
        solve(root->right,ind+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,0,ans);
        return ans;
    }
};
