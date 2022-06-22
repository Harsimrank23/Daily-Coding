/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      // if(!head || !head->next)
      //     return head;
        
        // step 1:
        Node * itr=head,*front=head;
        while(itr)
        {
            front=itr->next;
            Node * copy=new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            itr=front;
        }
        
        // step 2:
        itr=head;
        while(itr)
        {
            if(itr->random)
                itr->next->random=itr->random->next;
            
            itr=itr->next->next;
        }
        
        // step 3:
        itr=head;
        Node * dummy=new Node(0);
        Node * headcopy=dummy;
        
        while(itr)
        {
            front=itr->next->next;
            dummy->next=itr->next;
            itr->next=front;
            itr=itr->next;
            dummy=dummy->next;
        }
        
        return headcopy->next;
        
    }
};