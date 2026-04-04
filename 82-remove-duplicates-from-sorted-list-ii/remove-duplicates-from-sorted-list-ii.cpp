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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* pre=NULL;
        ListNode* curr=head;
        ListNode* post=head->next;
        while(curr!=NULL){
            if(post!=NULL && curr->val==post->val){
                while(post!=NULL && post->val==curr->val) post=post->next;
                if(pre) pre->next=post;
                else head=post;
                curr=post;
                if(post) post=post->next;
            }else{
                pre=curr;
                curr=post;
                if(post) post=post->next;
            }
        }
        return head;
    }
};