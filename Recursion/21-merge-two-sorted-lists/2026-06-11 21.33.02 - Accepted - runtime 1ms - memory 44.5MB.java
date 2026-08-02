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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null)
            return list2;
        if (list2 == null)
            return list1;

        ListNode temp = list1;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = list2;

        boolean swapped;

        do {
            swapped = false;
            temp = list1;

            while (temp != null && temp.next != null) {
                if (temp.val > temp.next.val) {
                    int x = temp.val;
                    temp.val = temp.next.val;
                    temp.next.val = x;
                    swapped = true;
                }
                temp = temp.next;
            }
        } while (swapped);

        return list1;
    }
}