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
    ListNode* removeNodes(ListNode* head) {
        int largest=INT_MIN;
        bool check=solve(head,largest);
        if(check){
            head=head->next;
        }
        return head;
    }
    bool solve(ListNode* head,int &largest){
        if(!head->next){
            largest=head->val;
            return false;
        }
        bool check=solve(head->next,largest);
        if(check){
            head->next=head->next->next;
        }
        if(largest>head->val){
            return true;
        }else{
            largest=head->val;
            return false;
        }
    }
};