/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
//     int length(ListNode *head)
//     {
//         int l=0;
//         ListNode *temp=head;
//         while(temp)
//         {
//             l++;
//             temp=temp->next;
//         }
//         return l;
//     }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(!headA || ! headB)
//             return NULL;
        
//         int l1=length(headA);
//         int l2=length(headB);
        
//         ListNode * ptr1,*ptr2;
//         int d=0;
//         if(l1>l2)
//         {
//             d=l1-l2;
//             ptr1=headA;
//             ptr2=headB;
//         }
//         else
//         {
//             d=l2-l1;
//             ptr1=headB;
//             ptr2=headA;
//         }
        
//         while(d)
//         {
//             ptr1=ptr1->next;
//             if(ptr1==NULL)
//                 return NULL;
//             d--;
//         }
        
//         while(ptr1!=NULL && ptr2!=NULL)
//         {
//             if(ptr1==ptr2)
//                 return ptr1;
//             ptr1=ptr1->next;
//             ptr2=ptr2->next;
//         }
//         return NULL;
        
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode * a=headA,*b=headB;
    
        while(a!=b)
        {
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        
        return a;
    }
};