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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         map<int,int>mp;
//         for(int i=0;i<inorder.size();i++)
//             mp[inorder[i]]=i;
        
//         TreeNode * root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        
//         return root;
//     }
    
//     TreeNode * helper(vector<int>& porder, int pStart,int pEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>mp)
//     {
//         if(pStart>pEnd || inStart>inEnd)
//             return NULL;
        
//         TreeNode * root=new TreeNode(porder[pStart]);
//         int inroot=mp[root->val];
//         int numleft=inroot-inStart;
        
//         root->left=helper(porder,pStart+1,pStart+numleft,inorder,inStart,inroot-1,mp);
        
//         root->right=helper(porder,pStart+numleft+1,pEnd,inorder,inroot+1,inEnd,mp);
        
//         return root;
//     }
    
    TreeNode * constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode * root = new TreeNode (preorder[preStart]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

TreeNode * buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
    
//     TreeNode* ok(vector<int>& pre,vector<int>& in,int &idx,int st,int ed,unordered_map<int,int> &mymap){
//         if(idx>pre.size() || st>ed){
//             return NULL;
//         }
        
//         int mid=mymap[pre[idx]];
        
//         TreeNode* root = new TreeNode(pre[idx++]);
        
//         root->left=ok(pre,in,idx,st,mid-1,mymap);
        
//         root->right=ok(pre,in,idx,mid+1,ed,mymap);
            
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int,int> mymap;
        
//         for(int i=0;i<inorder.size();i++){
//             mymap[inorder[i]]=i;
//         }
//         int idx=0;
//         return ok(preorder,inorder,idx,0,inorder.size()-1,mymap);
//     }
};