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
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* front = curr->next;
        prev->next = NULL;

        while(curr->next != NULL){
            curr->next = prev;
            prev = curr; curr = front; front = front!=NULL?front->next:front;
        }
        curr->next = prev;
        return curr;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseList(slow->next);
        ListNode *first = head, *second = newHead;
        while(second){
            if(first->val != second->val){
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newHead);
        return true;
    }
};