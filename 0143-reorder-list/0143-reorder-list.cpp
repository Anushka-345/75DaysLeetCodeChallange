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
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
    }
    ListNode* findMiddle(ListNode* head) {
    if(!head) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // slow points to middle node
    }
    void mergeListsInPlace(ListNode* l1, ListNode* l2) {
        while(l1 && l2) {
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;

            l1->next = l2;
            l2->next = l1Next;

            l1 = l1Next;
            l2 = l2Next;
        }
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode* mid = findMiddle(head);
        ListNode*tail = mid->next;
        mid->next = NULL;
        tail = reverseList(tail);
        mergeListsInPlace(head, tail);
        
    }
};