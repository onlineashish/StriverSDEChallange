/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0;
        int count2 = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1->next != NULL){
            count1++;
            temp1 = temp1->next;
        }
        while(temp2->next != NULL){
            count2++;
            temp2 = temp2->next;
        }
        if(temp1 != temp2) return NULL;
        int diff = abs(count1-count2);
        if(count1>count2){
            for(int i =0; i<diff;i++){
                headA = headA->next;
            }
        }
        if(count2>count1){
            for(int i =0; i<diff;i++){
                headB = headB->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;

    }
};
