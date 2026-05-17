/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify the insertion logic for the result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        
        // Loop runs as long as there are digits left in l1 OR l2, OR a remaining carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate the new carry and the digit value to store
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            
            // Move our result pointer forward
            curr = curr->next;
        }
        
        // The real head of the result list is next to the dummy head
        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the dummy head memory
        return result;
    }
};
