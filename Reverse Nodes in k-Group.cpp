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
    int lengthofLL(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = lengthofLL(head);

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr;
        ListNode *nex;

        while(len >=k){
            curr = prev->next;
            nex = curr->next;
            for(int i=1; i<k;i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len = len - k;

        }
        return dummy->next;

    }
};
