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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          int postStart = 0, postEnd = postorder.size() - 1;
          int inStart = 0, inEnd = inorder.size() - 1;

          map < int, int > mp;
          for (int i = inStart; i <= inEnd; i++) 
              mp[inorder[i]] = i;


          return helper(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }
    
    TreeNode * helper(vector<int>& porder, int pStart,int pEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&mp)
{
    if(pStart>pEnd || inStart>inEnd)
        return NULL;

    TreeNode * root=new TreeNode(porder[pEnd]);
    int inroot=mp[root->val];
    int numleft=inroot-inStart;

    root->left=helper(porder,pStart,pStart+numleft-1,inorder,inStart,inroot-1,mp);

    root->right=helper(porder,pStart+numleft,pEnd-1,inorder,inroot+1,inEnd,mp);

    return root;
}
};