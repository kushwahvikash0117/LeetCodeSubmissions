/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void InsertCopyInBetween(Node *head){
        Node *temp = head;
        while(temp){
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }
    void connectRandomPointers(Node *head){
        Node *temp = head;
        while(temp){
            Node *copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            } 
            else{
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node *getDeepCopy(Node *head){
        Node *temp = head, *dummy = new Node(-1), *res = dummy;
        while(temp){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        InsertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);
    }
};