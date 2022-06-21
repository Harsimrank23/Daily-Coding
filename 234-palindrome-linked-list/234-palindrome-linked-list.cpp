/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head && head->next==NULL)
            return true;
        
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *dummy=NULL;
        ListNode *nexx=NULL;
        ListNode * head2=slow->next;
        while(head2!=NULL)
        {
            nexx=head2->next;
            head2->next=dummy;
            dummy=head2;
            head2=nexx;
        }
        slow->next=dummy;
        slow=slow->next;
        while(slow)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};