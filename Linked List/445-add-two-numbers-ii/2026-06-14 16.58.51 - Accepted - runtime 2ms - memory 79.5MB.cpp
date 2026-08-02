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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        ListNode* temp=l1;
        while(temp!=NULL)
        {
            s1.push(temp->val);
            temp=temp->next;

        }
        temp=l2;
        while(temp!=NULL)
        {
            s2.push(temp->val);
            temp=temp->next;

        }
        int rem=0;
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;

        while(!s1.empty()||!s2.empty()||rem!=0)
        {
            int sum=0;
            if(!s1.empty()&&!s2.empty())
            {
                sum=s1.top()+s2.top()+rem;
                s1.pop();
                s2.pop();
            }
            else if(!s1.empty())
            {
                sum=s1.top()+rem;
                s1.pop();
            }
            else if(!s2.empty())
            {
                sum=s2.top()+rem;
                s2.pop();
            }
            else
                sum=rem;
    
           /* ListNode* prev=new ListNode(sum%10);
            prev->next=dummy;
            rem=sum/10;*/
            dummy->next=new ListNode(sum%10);
            rem=sum/10;
            dummy=dummy->next;            
        }                                                                                                                                                   
        dummy->next=NULL;
        ListNode* curr=head->next;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
};