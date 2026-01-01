// Intersection in Y Shaped Lists
// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

class Solution {
  public:
    int findListLen(Node* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    Node* moveHeaders(Node* head, int diff){
        while(diff--){
            head = head->next;
        }
        return head;
    }

    Node* intersectPoint(Node* head1, Node* head2) {
        int len1 = findListLen(head1);
        int len2 = findListLen(head2);

        if(len1 > len2)
            head1 = moveHeaders(head1, len1 - len2);
        else
            head2 = moveHeaders(head2, len2 - len1);

        while(head1 && head2){
            if(head1 == head2)
                return head1;
            head1 = head1->next;
            head2 = head2->next;
        }

        return NULL;
    }
};

// Time Complexity : O(4*N)
// Space Complexity : O(1)
