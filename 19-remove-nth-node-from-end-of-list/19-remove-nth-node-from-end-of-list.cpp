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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)    return NULL;
        ListNode* r=head;
        ListNode* t=head;
        while(n>0){
            t=t->next;
            n--;
        }
        if(t==NULL) return head->next;
        while(t->next!=NULL){
            r=r->next;
            t=t->next;
        }
        ListNode* temp=r->next->next;
        r->next=temp;
        return head;
    }
};