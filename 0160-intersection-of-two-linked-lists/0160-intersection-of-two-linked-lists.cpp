/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Boundary check
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* pA = headA;
        ListNode* pB = headB;
        
        // Loop terminates when pointers meet (either at the intersecting node or at nullptr)
        while (pA != pB) {
            // If pointer A reaches the end, redirect it to headB; else move to the next node
            pA = (pA == nullptr) ? headB : pA->next;
            
            // If pointer B reaches the end, redirect it to headA; else move to the next node
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        return pA;
    }
};