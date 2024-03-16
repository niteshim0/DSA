/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
  public void deleteNode(ListNode node) {
      //Approach
      //delete the next one // and changes the value in previous one

      ListNode next = node.next;
      node.val = next.val;
      node.next = node.next.next;
      
      
  }
}