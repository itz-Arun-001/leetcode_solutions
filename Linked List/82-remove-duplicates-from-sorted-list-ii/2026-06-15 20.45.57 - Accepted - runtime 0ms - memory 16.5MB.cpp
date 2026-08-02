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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>mp;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            mp[temp->val]++;
            temp=temp->next;

        }
        temp=head;
        ListNode* dummy=new ListNode(0);
        ListNode* t=dummy;
        for(auto p:mp)
        {
                if(p.second==1)
                {
                    dummy->next=new ListNode(p.first);
                    dummy=dummy->next;
                }
                //temp=temp->next;
        }
      //  delete dummy;
        delete temp;
        return t->next;
        
    }
};