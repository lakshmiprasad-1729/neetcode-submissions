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
    int ans = INT_MIN;
   int solve(TreeNode* root){
    if(root==nullptr) return 0;
    int a = solve(root->left) , b = solve(root->right);
    int val = max(root->val,max(root->val+a,root->val+b));
    ans = max(ans,max(val,root->val+a+b));
    return val;
   }
    int maxPathSum(TreeNode* root) {
    //    vector<int> pref = {0};
       solve(root);
       return ans;
    }
};
