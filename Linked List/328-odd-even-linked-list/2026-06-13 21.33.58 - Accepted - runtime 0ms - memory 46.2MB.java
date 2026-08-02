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
    public ListNode oddEvenList(ListNode head) {

        /*  ListNode odd=new ListNode(0);
        ListNode even=new ListNode(0);
        ListNode temp=head;
        while(temp!=null)
        {
            if(temp.val%2!=0)
            {
                odd.next=temp;
            }
            else{
                even.next=temp;
            }
            temp=temp.next;
        }
        odd=odd.next;
        temp=odd;
        while(odd.next!=null){
            odd=odd.next;
        }
        odd.next=even.next;
        return temp;
        ListNode temp=head;
        ListNode prev=null;
        ListNode next=null;
        ListNode curr=temp;
        int k=0;
        while(temp!=null)
        {
            k++;
            if(k%2!=0)
            {
                next=curr.next;
                curr.next=prev;
                prev=curr;
                curr=next;
        
        
        
        
            }
            temp=temp.next;
        }
        return head;*/

        if (head == null)
            return null;

        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenhead = even;

        while (even != null && even.next != null) {

            odd.next = even.next;
            odd = odd.next;

            even.next = odd.next;
            even = even.next;
        }

        odd.next = evenhead;
       // System.gc();

        return head;
    }
}