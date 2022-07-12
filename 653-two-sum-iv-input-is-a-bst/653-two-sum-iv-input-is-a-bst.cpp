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
class BSTiterator{
    public:
    stack<TreeNode *>st;
    // reverse=true->before
    //freverse=false->next;
    bool reverse=true;
    
    void pushAll(TreeNode *root)
    {
        for(;root!=NULL;)
        {
            st.push(root);
            if(reverse==true)
                root=root->right;
            else
                root=root->left;
        }
    }
    
    BSTiterator(TreeNode * root,bool isReverse)
    {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next()
    {
        TreeNode *root=st.top();
        st.pop();
        if(!reverse)
            pushAll(root->right);
        else
            pushAll(root->left);
        
        return root->val;
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i=l.next();
        int j=r.next();
        
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=l.next();
            else
                j=r.next();
        }
        return false;
    }
};