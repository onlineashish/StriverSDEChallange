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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        stack<int> st;
        while(fast != NULL && fast->next != NULL){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast !=NULL){
            slow = slow->next;
        }
        while(slow!=NULL){
            if(st.top() != slow->val){
                return false;
                
                
            }
            st.pop();
            slow = slow->next;
        }
        return true;
    }
};
