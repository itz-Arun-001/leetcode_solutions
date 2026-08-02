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
/*class Solution {
public:
    int nodelen(ListNode* head)
    {
        int l=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len=nodelen(head);
        int cnt=1;
        ListNode* temp=head;
        if(k==0)    return head;
        while(cnt<k-1){
            cnt++;
            temp=temp->next;
        }
        ListNode* t1=temp;
        ListNode*curr=temp->next;
        temp=temp->next;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(cnt<=len-k&&temp!=nullptr)
        {
            cnt++;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            temp=temp->next;


        }
       if(temp->next!=nullptr) prev->next=temp->next;
        t1->next=prev;
        return temp;
        */
        class Solution {
public:
    int nodelen(ListNode* head)
    {
        int l=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len=nodelen(head);
        ListNode* temp=head;
        int c=1;

        while(c<k){
            c++;
            temp=temp->next;
        }
        ListNode* a=temp;
        temp=head;
        c=1;
        while(c<len-k+1)
        {
            c++;
            
            temp=temp->next;

        }
        ListNode* b=temp;
        int t=a->val;
        a->val=b->val;
        b->val=t;

        return head;
    }
};