/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val;}
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
   /* public static long rint(long num) {
    long reversed = 0;
    
    while (num != 0) {
        long lastDigit = num % 10;        // Extract the last digit
        reversed = reversed * 10 + lastDigit; // Append it to the reversed number
        num = num / 10;                 // Remove the last digit from the original number
    }
    
    return reversed;
}
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        long a=0;
        while(l1!=null)
        {
            a=(a*10)+l1.val;
            l1=l1.next;
        }
        long b=0;
         while(l2!=null)
        {
            b=(b*10)+l2.val;
            l2=l2.next;
        }
        a=rint(a);
        b=rint(b);
        long c=a+b;
        ListNode ans=new ListNode(0);
        ListNode head=ans;
        if(c==0)    return new ListNode(0);
        while(c>0)
        {
            ans.next=new ListNode(c%10);
            c/=10;
            ans=ans.next;
        }
        ans.next=null;
        return head.next;


*/
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

    int rem=0;
    int sum=0;
    ListNode dummy =new ListNode(0);
    ListNode head=dummy;
    while(l1!=null||l2!=null||rem!=0)
    {   sum=0;
     if( l1==null && l2==null)
            sum+=rem;
        else if(l1==null)
            sum+=l2.val+rem;
        else if(l2==null)
            sum+=l1.val+rem;
       
        else   sum+=l1.val+l2.val+rem;
        dummy.next= new ListNode(sum%10,null);
        rem=sum/10;
        dummy=dummy.next;
        if(l1!=null)   l1=l1.next;
        if(l2!=null)    l2=l2.next;
        
    }
    return head.next;
        
    }
}