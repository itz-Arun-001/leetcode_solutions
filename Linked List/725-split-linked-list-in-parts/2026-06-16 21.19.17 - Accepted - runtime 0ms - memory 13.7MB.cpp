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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        ListNode* curr=head;
        int len=0;
        while(curr!=nullptr)
        {
            len++;
            curr=curr->next;
        }
        curr=head;
        int size=len/k;
        int extra=len%k;
        for(int i=0;i<k;i++)
        {
            ListNode* newnode=curr;
            int s=size+(i<extra?1:0);
            for(int j=1;j<s;j++)
            {
                if(curr!=NULL)
                {
                    curr=curr->next;
                }
            }
            if(curr!=NULL)
            {
                ListNode* temp=curr->next;
                curr->next=nullptr;
                curr=temp;
            }
            ans.push_back(newnode);
        }
        return ans;
       
    }
};