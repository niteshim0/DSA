vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        vector<pair<int,int>> vp;
        if (head == NULL || head->next == NULL) return vp;

        Node* start = head;
        Node* last = head;

        // Move 'last' to the end of the doubly linked list
        while (last->next != NULL) {
            last = last->next;
        }

        while (start != last && last->next != start) {
            int sum = start->data + last->data;

            if (sum == target) {
                vp.push_back({start->data, last->data});
                start = start->next;
                last = last->prev;
            } else if (sum < target) {
                start = start->next;
            } else {
                last = last->prev;
            }
        }

        return vp;
      }

// Time Complexity : O(N+N/2)
// Space Complexity : O(no of pairs found)

