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
    ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;
      ListNode* first = head;
      ListNode* sec = head->next;
        ListNode*prev = NULL;
        head = sec;

     while(first && sec){
    ListNode* thrid = sec->next;  // store next pair

    // Swap current pair
    sec->next = first;
    first->next = thrid;

    // Connect previous pair with current swapped pair
    if(prev){
        prev->next = sec;
    }
    else{
        prev = first;
    }

    // Move prev and first to next pair
    prev = first;
    first = thrid;
    sec = (first) ? first->next : NULL;
}

      return head;
    }
};