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
    ListNode* curr = head ;
    ListNode* prev = NULL;
    int i = 1 ;

    while(curr && i != left){
        prev = curr;
        curr = curr->next;
        i++;
    }
    ListNode* StartNode = prev ;
    ListNode* start = curr;
     prev = NULL;
    while(curr &&  i != right+1){
        ListNode*  front = curr->next;
        curr->next = prev ;
        prev = curr;
        curr = front;
        i++;
    }
    start->next = curr;
    if(StartNode){
        StartNode->next = prev ;
    }
    else{
        return prev;
    }
     return head;
     }
};



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
