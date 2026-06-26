/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return 0;
        ListNode *slowPtr = head, *fastPtr = head->next;
        bool hascycle = 0;
        while(fastPtr != NULL && fastPtr != slowPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next?fastPtr->next->next : NULL;
        }
        if(fastPtr == slowPtr) hascycle = 1;
        return hascycle;
    }
};