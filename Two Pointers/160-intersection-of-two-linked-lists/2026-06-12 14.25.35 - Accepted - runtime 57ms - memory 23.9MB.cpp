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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        /*while(temp1!=NULL&&temp1->next!=NULL)
        {
            temp1=temp1->next;

        }
        while(temp2!=NULL&&temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp1->next=headB;
        temp2->next= headA;
        while(temp1!=NULL&&temp2!=NULL)
        {
            if(temp1->val==temp2->val)
            {
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;*/
        while(temp1!=temp2)
        {
            if(temp1!=NULL)  temp1=temp1->next;
            else temp1=headB;
            if(temp2!=NULL)   temp2=temp2->next;
            else   temp2=headA;
            if(temp1==temp2)  return temp1;
            

        }
        return temp1;
    }
};