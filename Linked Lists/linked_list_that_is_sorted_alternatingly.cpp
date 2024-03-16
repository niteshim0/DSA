/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    Node* reverseList(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void sort(Node **head)
    {
         // Code here
         if(*head == NULL || (*head)->next == NULL){
             return;
         }
         Node* h1 = new Node(-1);
         Node* h2 = new Node(-1);
         Node* asc = h1;
         Node* dsc = h2;
         Node* curr = *head;
         
         while(curr!=NULL){
             asc->next = curr;
             asc = asc->next;
             curr = curr->next;
             if(curr!=NULL){
                 dsc->next = curr;
                 dsc = dsc->next;
                 curr = curr->next;
             }
             if(asc->next !=NULL && asc->next->next!=NULL){
                 asc->next = NULL;
             }
             dsc->next = NULL;
         }
         h1 = h1->next;
         h2 = h2->next;
         h2 = reverseList(h2);
         asc->next = h2;
         *head = h1;
         
    }
};