/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(x) : val(x), next(nullptr) {}
 * ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If there's only one node, deleting it returns an empty list
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next->next; // Start fast two steps ahead
        
        // When fast reaches the end, slow will point to the node BEFORE the middle node
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Delete the middle node by skipping it
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle; // Free memory
        
        return head;
    }
};