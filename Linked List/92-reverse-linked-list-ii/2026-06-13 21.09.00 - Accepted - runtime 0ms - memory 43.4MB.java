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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy=new ListNode(0,head);
        ListNode temp=dummy;
        int k=0;
        while(k<left-1)
        {   k++;
            temp=temp.next;

        }
        ListNode curr=temp.next;
        ListNode prev=null;
        ListNode next=null;
        ListNode start=curr;
        //System.gc();
        for(int i=0;i<=right-left;i++)
        {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
      //  System.gc();
        temp.next=prev;
        start.next=curr;
        System.gc();
        return dummy.next;
        
    }
}