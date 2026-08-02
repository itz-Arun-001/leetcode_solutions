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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        /*   
         if(head==null) return null;
        if(n==1)
        {
            return head.next;
        }
        int k=0;
        ListNode prev=null;
        ListNode curr=head;
        while(curr!=null){
            k++;
            if(k==n)
            {
                prev.next=prev.next.next;
                break;
        
            }
            prev=curr;
            curr=curr.next;
        }
        return head;*/

        ListNode dummy = new ListNode(0, head);
        ListNode slow = dummy;
        ListNode fast = dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
           //System.gc();
        }
        System.gc();
        while (fast != null) {

            fast = fast.next;
            slow = slow.next;
            System.gc();
        }
        slow.next = slow.next.next;
        System.gc();
        return dummy.next;

    }
}