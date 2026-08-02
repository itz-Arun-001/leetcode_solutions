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
    public ListNode partition(ListNode head, int x) {
         ListNode l1=new ListNode(0);
        ListNode l2=new ListNode(0);
        ListNode l2h=l2;
        ListNode ans=l1;
        ListNode temp=head;
        while(temp!=null)
        {
            if(temp.val<x)
            {
                l1.next=new ListNode(temp.val);
                l1=l1.next;
            }
            else{
                l2.next=new ListNode(temp.val);
                l2=l2.next;
            }
            temp=temp.next;
        }
        l2.next=null;
        l1.next=l2h.next;
        return ans.next;
        
    }
}