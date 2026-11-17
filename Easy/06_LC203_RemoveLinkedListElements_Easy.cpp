// LeetCode 203 - Remove Linked List Elements
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while(temp->next != nullptr) {
            if(temp->next->val == val) {
                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
            }
            else {
                temp = temp->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
