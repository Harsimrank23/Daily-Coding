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

class NodeVal{
    public:
    int maxNode,minNode,maxSize,sum;
    NodeVal(int minNode,int maxNode,int maxSize,int sum)
    {
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
        this->sum=sum;
    }
};
class Solution {
private:
    NodeVal helper(TreeNode * root,int &maxSum)
    {
        if(!root)
            return NodeVal(INT_MAX,INT_MIN,0,0);
        
        auto left=helper(root->left,maxSum);
        auto right=helper(root->right,maxSum);
        
        if(left.maxNode<root->val && root->val<right.minNode)
        {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            int maximum = max(root->val, right.maxNode);
            int minimum = min(root->val, left.minNode);
            
            return NodeVal(minimum,maximum,left.maxSize,right.maxSize+currSum);
        
        }
        
        return NodeVal(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize),0);
    }
    
public:
    int maxSumBST(TreeNode* root) {
     
        int maxSum = 0;
        helper(root,maxSum);
        return maxSum;
    }
};

// class Solution {
//     struct Subtree{
//       int maxVal, minVal, sum;  
//         bool isBST;
//         Subtree(int mx, int mn, int s, bool bst){
//             maxVal = mx;
//             minVal = mn;
//             sum = s;
//             isBST = bst;
//         }
//     };
// public:
//     Subtree computeBstSum(TreeNode* root, int& maxSum){
//         if(!root){
//             return {INT_MIN, INT_MAX, 0, true}; // <max, min, sum, isbst>
//         }
        
//         auto left = computeBstSum(root->left, maxSum);
//         auto right = computeBstSum(root->right, maxSum);
        
//         if(left.isBST && right.isBST && (left.maxVal < root->val && root->val < right.minVal)){// check for bst
//             // max of left has to be lesser than root 
//             // min or right has to be greater than root
//             int currSum = root->val + left.sum + right.sum;
//             maxSum = max(maxSum, currSum);
//             int maximum = max(root->val, right.maxVal);
//             int minimum = min(root->val, left.minVal);
            
//             return {maximum, minimum, currSum, true};
//         }
        
//         return {-1,-1, 0, false};  // not possible
//     }

// };