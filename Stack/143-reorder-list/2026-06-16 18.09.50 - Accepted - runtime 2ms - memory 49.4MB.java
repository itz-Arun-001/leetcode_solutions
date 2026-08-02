/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if(head==null||head.next==null)        return;
        ListNode temp=head;
        
        ListNode slow=head;
        ListNode fast=head;
       // ListNode temp1=head;
        
        while(fast!=null&&fast.next!=null)
        {
            fast=fast.next.next;
            temp=slow;
            slow=slow.next;
        }
        temp.next=null;
        //ListNode dum=temp1;
        ListNode curr=slow;
        ListNode prev=null;
        ListNode next=null;
        while(curr!=null)
        {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
         System.gc();

        ListNode first=head;
        ListNode second=prev;

        while(first!=null&&second!=null)
        {
            ListNode fnext=first.next;
            ListNode snext=second.next;
            first.next=second;
            if(fnext!=null)
            {
                second.next=fnext;
            }
            first=fnext;
            second=snext;
        }
        System.gc();
       // return head;

    }
}