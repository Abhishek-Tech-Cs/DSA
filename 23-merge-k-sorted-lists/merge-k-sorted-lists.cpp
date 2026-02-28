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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push(make_pair(lists[i]->val,lists[i]));
        }
        ListNode* ans=NULL;
        ListNode* dummy=NULL;
        while(!pq.empty()){
            pair<int,ListNode*>temp=pq.top();
            pq.pop();
            if(!ans){
                ans=temp.second;
                dummy=ans;
            }else {
                dummy->next=temp.second;
                dummy=temp.second;
            }
            if(temp.second->next) pq.push(make_pair(temp.second->next->val,temp.second->next));
        }
        return ans;
    }
};