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
    public ListNode deleteMiddle(ListNode head) {
      /*  if(head==null||head.next==null)  return null;
        ListNode slow=head;
        ListNode fast=head;
        ListNode prev=null;
        while(fast!=null&&fast.next!=null)
        {

            fast=fast.next.next;
            prev=slow;
            slow=slow.next;
        }
        prev.next=slow.next;
        System.gc();
        return head;*/
        if(head==null||head.next==null)  return null;
        ListNode slow=new ListNode(-1);
        ListNode fast=head;
       // ListNode prev=null;
       slow.next=head;
        while(fast!=null&&fast.next!=null)
        {

            fast=fast.next.next;
            //prev=slow;
            slow=slow.next;
        }
        //prev.next=slow.next;
        slow.next=slow.next.next;
        //System.gc();
        return head;

    }
}