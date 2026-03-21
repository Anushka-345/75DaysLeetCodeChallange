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
        if (head == NULL || head->next == NULL)
    return true;

ListNode *temp = head;
int count = 0;

// Count nodes
while (temp) {
    count++;
    temp = temp->next;
}

// Move to middle
count /= 2;
ListNode *curr = head;
ListNode *prev = NULL;

while (count--) {
    prev = curr;
    curr = curr->next;
}

// Break list into two halves
prev->next = NULL;

// Reverse second half
ListNode *front;
prev = NULL;
while (curr) {
    front = curr->next;
    curr->next = prev;
    prev = curr;
    curr = front;
}

// Compare both halves
ListNode* head1 = head;
ListNode* head2 = prev;

while (head1 && head2) {
    if (head1->val != head2->val)
        return false;
    head1 = head1->next;
    head2 = head2->next;
}

return true;  // ✅ FIX
    }
};