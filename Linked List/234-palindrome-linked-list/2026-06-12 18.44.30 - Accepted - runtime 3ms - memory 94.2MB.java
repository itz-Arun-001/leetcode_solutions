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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null)
{
    return true;
}
        ListNode slow=head;
        ListNode fast=head;
        ListNode temp=head; 
        while(fast!=null&&fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;

        }

        ListNode curr=slow;
        ListNode prev=null;
        ListNode next=null;
       // slow.next=null;
        while(curr!=null)
        {
            next = curr.next;
            curr.next = prev;
            prev = curr; 
            curr = next;
        }
        int f=0;
      ListNode p1 = head;
       ListNode p2 = prev;

              while (p2 != null) {
    if (p1.val != p2.val) {
        return false;
    }

            p1 = p1.next;
         p2 = p2.next;
}

return true;
 //return false;
        
        
    }
}