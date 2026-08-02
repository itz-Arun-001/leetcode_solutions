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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(prev->next!=NULL&&prev->next->next!=NULL)
        {
            ListNode* first=prev->next;
            ListNode* second=prev->next->next;
            first->next=second->next;
            second->next=first;
            prev->next=second;
            prev=first;

        }
        return dummy->next;
        /*ListNode* prev=nullptr;
        ListNode* second;
        while(curr!=nullptr&&curr->next!=nullptr)
        {
            second=curr->next;
            curr->next=second;
            second->next=curr->next;
            prev=second;
            prev=prev->next;
            curr=curr->next->next;
           /* first=next;
            //first->next=temp;
            first=first->next->next;
            second=second->next->next;*/
        //}
       // return head;*/
    }
};