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
    void help(ListNode* head,vector<int>& critical)
    {
        ListNode* prev;
        ListNode* next;
        ListNode* curr;
        prev=NULL;
        curr=head;
        if(curr!=NULL)
        {
            next=curr->next;
        }
        int i=0;
        while(curr)
        {
            if(prev!=NULL&&next!=NULL)
            {
                if((curr->val<prev->val&&curr->val<next->val)||(curr->val>prev->val&&curr->val>next->val))
                {
                    critical.push_back(i);
                }
                
            }
            prev=curr;
            curr=next;
            if(next!=NULL)
                next=next->next;
            i++;
        }
        if(critical.size()<2) {
            critical.clear();
            critical.push_back(-1);
             critical.push_back(-1);
        }
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>temp;
        help(head,temp);
       if(temp.size() == 2 && temp[0] == -1 && temp[1] == -1)
            return {-1, -1};
       // sort(temp.begin(),temp.end());
        int minval=INT_MAX;
        for(int i=1;i<temp.size();i++)
        {
            minval=min(minval,temp[i]-temp[i-1]);
        }
        return {minval,temp[temp.size()-1]-temp[0]};

    }
};
