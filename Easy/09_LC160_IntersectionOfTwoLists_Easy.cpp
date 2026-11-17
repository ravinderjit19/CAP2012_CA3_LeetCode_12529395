// LeetCode 160 - Intersection of Two Linked Lists
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa=headA;
        ListNode* tempb=headB;

        while(tempa!=tempb){
            if(tempa==nullptr){
                tempa=headB;
            }
            else{
                tempa=tempa->next;
            }
            if(tempb==nullptr){
                tempb=headA;
            }
            else{
                tempb=tempb->next;
            }
        }    
        return tempa;    
    }
};
