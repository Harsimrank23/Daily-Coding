/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        
        queue<Node *>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            
            Node *p=q.front();
            q.pop();
            if(p)
            {
                p->next=q.front();
            
                if(p->left)
                    q.push(p->left);

                if(p->right)
                    q.push(p->right);
            }
                
            
            else if(!p && !q.empty())
                q.push(NULL);
        }
        return root;
        

// while(!q.empty()){
// Node* tmp = q.front();
// q.pop();
// if(tmp){
// tmp->next = q.front();
// if(tmp->left != NULL){
// q.push(tmp->left);
// }
// if(tmp->right != NULL){
// q.push(tmp->right);
// }
// }
// else if(tmp==NULL && !q.empty()){
// q.push(NULL);
// }
// }
// return root;
    }
};