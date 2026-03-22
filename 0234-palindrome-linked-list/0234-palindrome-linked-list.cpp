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
         if (!head || !head->next) return true;

        ListNode *temp = head;
        int count = 0 ;
        while(temp){
            count++;
            temp = temp->next;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        count /= 2 ;
        while(count--){
            prev = curr;
            curr = curr->next;
        }
        ListNode *front = NULL;
        prev = NULL;
        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr= front;
        }
         ListNode *head1 = head;
    ListNode *head2 = prev;

    while (head2) {
        if (head1->val != head2->val) {  // ✅ correct
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
    }
};