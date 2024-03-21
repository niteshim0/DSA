/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  if(head == null || head.next == null){
          return head;
      }
       prev = null;
       current = head;
       next = head.next;
      while(current!=null){
          current.next = prev;
          prev = current;
          current = next;
          if(next!=null) next = next.next;
      }
      return prev;
};