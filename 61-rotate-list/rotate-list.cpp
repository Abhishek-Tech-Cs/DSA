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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head) return head;
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        k=k%size;
        while(k!=0){
            ListNode* pre=NULL;
            ListNode* curr=head;
            while(curr->next){
                pre=curr;
                curr=curr->next;
            }
            curr->next=head;
            head=curr;
            pre->next=NULL;
            k--;
        }
        return head;
    }
};