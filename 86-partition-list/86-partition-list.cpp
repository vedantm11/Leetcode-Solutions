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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* small = new ListNode (-1000);
        ListNode * large = new ListNode (-1001);
        ListNode* temp = large;
        ListNode* temp2 = small;
        while(head != NULL){
            if(head->val < x){
                small->next = head;
                small = small->next;
            } 
            else{
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        small->next = temp->next;
        large->next = NULL;
        return temp2->next;
        
        
    }
};