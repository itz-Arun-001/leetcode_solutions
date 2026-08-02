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
    public ListNode removeElements(ListNode head, int val) {
        while (head != null && head.val == val) {
            head = head.next;
        }
       
        ListNode temp=head;
        ListNode prev=null;
        while(temp!=null)
        {
              
            if(temp.val==val)
            {
                prev.next=prev.next.next;//or prev.next=temp.next //as
                //1 -> 2 -> 6 -> 3 -> 6 -> 4
                    // ↑    ↑
                  //  prev  temp
                  //prev.next.next=3=temp.next
            }
            else{
            prev=temp;}
            temp=temp.next;
        }
        return head;
    }
}