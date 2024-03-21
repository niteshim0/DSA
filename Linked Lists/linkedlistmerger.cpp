/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list1Start = NULL;
        ListNode* list1End = NULL;
        ListNode* temp = list1;
        for(int i = 0;i<=b+1;i++){
            if(i == a-1){
                list1Start = temp;
            }
            if(i == b+1){
                list1End = temp;
                break;
            }
            temp = temp->next;
        }
        list1Start->next = list2;

        temp = list2;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = list1End;
        return list1;
    }
};