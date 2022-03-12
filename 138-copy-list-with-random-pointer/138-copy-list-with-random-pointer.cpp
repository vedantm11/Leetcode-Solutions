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
    Node* copyRandomList(Node* head) {
       if(!head) return NULL;
        Node* curr = head;
        
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
       
        while(curr!=NULL){
            if(curr->next!=NULL){
                curr->next->random = curr->random==NULL ? NULL:curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* org = head;
        Node* temp = head->next;
        Node* copy = temp;
       
        while(org!=NULL){
            org->next = org->next->next;
            temp->next = temp->next!=NULL? temp->next->next:temp->next;
            org = org->next;
            temp = temp->next;
        }
        return copy;
    }
};