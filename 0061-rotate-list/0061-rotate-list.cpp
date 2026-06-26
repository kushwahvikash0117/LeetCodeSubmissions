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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next ==NULL) return head;

        int len=1;
        ListNode *temp = head;
        while(temp->next){
            len++;
            temp = temp->next;
        } 

        k = k % len;

        if(k == 0) return head;
        
        ListNode *first = head, *second = head;
        while(k--){
            first = first->next;
        }
        while(first->next){
            first = first->next;
            second = second->next;
        }
        first->next = head;
        ListNode *newHead = second->next;
        second->next = NULL;
        return newHead;
    }
};