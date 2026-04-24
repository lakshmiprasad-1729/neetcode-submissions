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
    bool check(TreeNode* p ,TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr && q!=nullptr) return false;
        if(p!=nullptr && q==nullptr) return false;

        if(p->val != q->val) return false;
        bool a = check(p->right,q->right) , b = check(p->left,q->left);
        return a&b;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;

        bool a = check(root,subRoot) , b = isSubtree(root->left,subRoot),
        c = isSubtree(root->right,subRoot);
        return a | b| c;
    }
};
