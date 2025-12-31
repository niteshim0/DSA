// Approach I :: New List + Reverse Original  Comparison

class Solution {
  public:
    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        // create copy
        Node* dummy = new Node(0);
        Node* tail = dummy;
        Node* temp = head;

        while(temp){
            tail->next = new Node(temp->data);
            tail = tail->next;
            temp = temp->next;
        }

        Node* copy = dummy->next;
        delete dummy;

        // reverse copied list
        Node* rev = reverseList(copy);

        // compare both
        Node* p1 = head;
        Node* p2 = rev;

        while(p1 && p2){
            if(p1->data != p2->data)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Approach II :: Using Stack(For reversal purpose)

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        stack<int> st;
        Node* temp = head;
        while(temp!=NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        
        temp = head;
        while(temp!=NULL && !st.empty()){
            if(temp->data != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        
        return true;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(N)

// Approach III :: Using Fast and Slow Pointers

class Solution {
public:
    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* curr = head;

        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if(!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        // Find middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip middle node for odd length
        if(fast != NULL) {
            slow = slow->next;
        }

        // Reverse second half
        Node* secondHalf = reverseList(slow);
        Node* firstHalf = head;

        // Compare halves
        while(secondHalf){
            if(firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)