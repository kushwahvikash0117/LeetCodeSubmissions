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

    ListNode* getKthNode(ListNode* temp, int k){
        k--;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *prevLast = NULL;
        while(temp){
            ListNode *kThNode = getKthNode(temp, k);
            if(kThNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode *nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseList(temp);
            if(temp == head){
                head = kThNode;
            }
            else{
                prevLast->next = kThNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};