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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDis = INT_MAX;
        int maxDis = -1;
        ListNode* pre = NULL;
        ListNode* curr = head;
        int preIdx = -1,currIdx = 0;
        int firCriticalIdx = -1;
        while(curr != NULL){
            if(pre != NULL && curr -> next != NULL){
                if((curr->val > pre->val && curr->val > curr->next->val) || (curr->val < pre->val && curr->val < curr->next->val)){
                    if(preIdx != -1) minDis=min(minDis,currIdx-preIdx);
                    if(firCriticalIdx == -1) firCriticalIdx = currIdx;
                    else maxDis = max(maxDis, currIdx - firCriticalIdx);
                    preIdx = currIdx;
                }
            }
            pre = curr;
            curr = curr->next;
            currIdx++;
        }
        if(minDis == INT_MAX) minDis = -1;
        return {minDis, maxDis};
    }
};