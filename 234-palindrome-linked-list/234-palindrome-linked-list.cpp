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
    ListNode* ReverseList(ListNode* head)
    {
        if(head->next==NULL)    return head;
        ListNode* prev=NULL;
        ListNode* ne=NULL;
        while(head!=NULL){
            ne=head->next;
            head->next=prev;
            prev=head;
            head=ne;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
      if(head==NULL || head->next==NULL)    return true;  
      ListNode* slow=head;
      ListNode* fast=head;
     while(fast->next!=NULL && fast->next->next!=NULL)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
     slow->next=ReverseList(slow->next);
     slow=slow->next;   
     while(slow!=NULL)
     {
         if(slow->val!=head->val)   return false;
         slow=slow->next;
         head=head->next;
     }
     return true;   
    }
};