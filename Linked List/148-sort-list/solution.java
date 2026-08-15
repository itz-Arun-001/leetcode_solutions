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
    public ListNode sortList(ListNode head) {
        if(head==null||head.next==null)
        {
            return head;

        }
        ListNode slow=head;
        ListNode fast=head;
        while(fast.next!=null&&fast.next.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        ListNode mid=slow.next;
        slow.next=null;
        ListNode left=sortList(head);
        ListNode right=sortList(mid);
        return join(left,right);
        
    }
    ListNode join(ListNode l,ListNode r)
    {
        ListNode dummy=new ListNode(0);
        ListNode temp=dummy;
        while(l!=null&&r!=null)
        {
            if(l.val<r.val)
            {
                dummy.next=l;
                dummy=l;
                l=l.next;
            }
            else{
                dummy.next=r;
                dummy=r;
                r=r.next;

            }
        }
        if(l!=null)
            dummy.next=l;
        if(r!=null)
            dummy.next=r;
        return temp.next;
    }
}
