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
        unordered_map<int,int>m;
        ListNode* temp=head;
        int i=0,size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        
        while(head!=NULL){
            if(m.count(size-i-1)>0) m[size-i-1]+=head->val;
            else m[i]=head->val;
            i++;
            head=head->next;
        }

        int ans=INT_MIN;
        for(auto i:m) ans=max(ans,i.second);
        return ans;
    }
};