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
    TreeNode* solve(vector<int>& p,vector<int>& in,int l, int r){
        if(l > r) return nullptr;
        int it = upper_bound(p.begin(),p.end(),-1000)-p.begin();
        if(it >= (int)p.size()) return nullptr;
        TreeNode* node = new TreeNode(p[it]);
        int m;
        for(int j = l ; j <= r ; j++){
            if(in[j]==p[it]){
                m = j; break;
            }
        }
        p[it] = -1000;
        node->left = solve(p,in,l,m-1);
        node->right = solve(p,in,m+1,r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,(int)inorder.size()-1);
    }
};
