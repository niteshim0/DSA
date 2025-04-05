class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* current = head;
        Node* prev = NULL;
        while(current!=NULL){
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        head = reverseList(head);
        Node* temp = head;
        int carry = 1;
        int sum = 0;
        while(temp!=NULL){
            sum = carry + temp->data;
            temp->data = sum%10;
            carry = sum/10;
            if(carry==0) break;
            temp = temp->next;
        }
        head = reverseList(head);
        if(carry!=0){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
// Time Complexity : O(3N)
// Space Complexity : O(1)
// Three Pass solution


// Solution without reversal
// recursion is used to backtrack(one of the ways to reverse travel singly ll)

class Solution {
  public:
    int addHelper(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = addHelper(temp->next);
        temp->data = temp->data + carry;
        if(temp->data<10){
            carry = 0;
            return carry;
        }
        temp->data = 0;
        return 1;
    }
    Node* addOne(Node* head) {
        int carry = addHelper(head);
        if(carry!=0){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};