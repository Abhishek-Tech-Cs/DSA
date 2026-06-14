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
    int pairSum(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* curr=slow->next;
        ListNode* pre=NULL;
        while(curr!=NULL){
            ListNode* post=curr->next;
            curr->next=pre;
            pre=curr;
            curr=post;
        }
        slow->next=pre;
        slow=slow->next;
        int ans=INT_MIN;
        while(slow!=NULL){
            ans=max(ans,slow->val+head->val);
            head=head->next;
            slow=slow->next;
        } 
        return ans;   
    }
};