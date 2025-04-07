Node * removeDuplicates(struct Node *head)
    {
        Node* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            Node* nextNode = temp->next;
            while(nextNode!=NULL && nextNode->data == temp->data){
                nextNode = nextNode->next;
            }
            temp->next = nextNode;
            if(nextNode) nextNode->prev = temp;
            temp = temp->next;
        }
        return head;
    }
// Time Complexity : O(N)
// Space Complexity : O(1)