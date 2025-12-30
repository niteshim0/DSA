// Approach I :: Reversal + Add

class Solution {
public:

    Node* reverseList(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0)
            head = head->next;
        return head ? head : new Node(0);
    }

    Node* addTwoLists(Node* head1, Node* head2) {

        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);

        head1 = reverseList(head1);
        head2 = reverseList(head2);

        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) { sum += head1->data; head1 = head1->next; }
            if (head2) { sum += head2->data; head2 = head2->next; }

            tail->next = new Node(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }

        return reverseList(dummy->next);
    }
};

// Time Complexity : O((M + N))
// Space Complexity : O(1)

// Approach II :: Stack Based

/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
   Node* addTwoLists(Node* l1, Node* l2) {
    stack<int> s1, s2;

    while (l1) { s1.push(l1->data); l1 = l1->next; }
    while (l2) { s2.push(l2->data); l2 = l2->next; }

    int carry = 0;
    Node* head = NULL;

    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;
        if (!s1.empty()) { sum += s1.top(); s1.pop(); }
        if (!s2.empty()) { sum += s2.top(); s2.pop(); }

        Node* node = new Node(sum % 10);
        node->next = head;
        head = node;

        carry = sum / 10;
    }
    
    while(head!=NULL && head->data == 0){
        head = head->next;
    }

    return head;
   }
};
// Time Complexity : O(M+N)
// Space Complexity : O(max(M,N))