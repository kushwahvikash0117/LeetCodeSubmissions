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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB; 
        int l1 = 0, l2 = 0, diff;
        while(t1){
            l1++;
            t1 = t1->next;
        }
        while(t2){
            l2++;
            t2 = t2->next;
        }
        t1 = headA; t2 = headB;
        if(l1>l2){
            diff = l1-l2;
            while(diff){
                t1 = t1->next;
                diff--;
            }
        }
        else if(l2>l1){
            diff = l2-l1;
            while(diff){
                t2 = t2->next;
                diff--;
            }
        }
        while(t1 != t2 && t1 != NULL && t2 != NULL){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};