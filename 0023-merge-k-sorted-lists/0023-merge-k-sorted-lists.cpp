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
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1), *res = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                res->next = l1;
                res = l1;
                l1 = l1->next;
            }
            else{
                res->next = l2;
                res = l2;
                l2 = l2->next;
            }
        }
        if(l1) res->next = l1;
        else res->next = l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];

        ListNode* second = lists[1];
        lists.erase(lists.begin() + 1);
        ListNode* mergeHead = mergeKLists(lists);
        return merge2Lists(second, mergeHead);
    }
};