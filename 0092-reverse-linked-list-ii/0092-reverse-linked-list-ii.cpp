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
     ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right || !head->next) return head;

    ListNode *curr = head;
    ListNode *prev = NULL;
    int i = 1;

    // Step 1: Move to 'left'
    while (curr != NULL && i != left) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    ListNode *StartPoint = prev;  // node before left
    ListNode *start = curr;       // first node of sublist

    prev = NULL;

    // Step 2: Reverse till right
    while (curr != NULL && i != right + 1) {
        ListNode *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
        i++;
    }

    // Step 3: Connect tail of reversed part
    start->next = curr;

    // Step 4: Connect head part
    if (StartPoint != NULL) {
        StartPoint->next = prev;
    } else {
        return prev; // new head if left == 1
    }

    return head;

}
};