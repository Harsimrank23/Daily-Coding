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
    int maxi=INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int leftsum=max(0,helper(root->left));
        int rightsum=max(0,helper(root->right));
        maxi=max(maxi,leftsum+rightsum+root->val);
        
        return root->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }
};