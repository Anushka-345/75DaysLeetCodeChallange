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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
       ListNode *temp =head ;
       ListNode *curr = head->next ;
       while(curr){
        if(curr->val==temp->val){
            temp->next = curr->next ;
            delete curr ;
            curr = temp->next;
        
        }
        else{
            temp = temp->next;
            curr = curr->next;
        }
       }
       return head;
    }
};