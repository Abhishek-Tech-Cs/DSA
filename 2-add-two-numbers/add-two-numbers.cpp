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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* tempAns = ans;
        while(temp1 || temp2 || carry){
            if(temp1 && temp2){
                int sum = temp1->val + temp2->val;
                int num;
                if(carry == 1) sum++;
                if(sum > 9){
                    num = sum % 10;
                    carry = 1;
                }else{
                    num = sum;
                    carry = 0;
                }
                ListNode* newNode = new ListNode(num);
                tempAns->next = newNode;
                tempAns = newNode;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }else if(temp1){
                int val = temp1->val;
                int num;
                if(carry == 1) val++;
                if(val > 9){
                    num = val % 10;
                    carry = 1;
                }else{
                    num = val;
                    carry = 0;
                }
                ListNode* newNode = new ListNode(num);
                tempAns->next = newNode;
                tempAns = newNode;
                temp1 = temp1->next;
            }else if(temp2){
                int val = temp2->val;
                int num;
                if(carry == 1) val++;
                if(val > 9){
                    num = val % 10;
                    carry = 1;
                }else{
                    num = val;
                    carry = 0;
                }
                ListNode* newNode = new ListNode(num);
                tempAns->next = newNode;
                tempAns = newNode;
                temp2 = temp2->next;
            }else{
                ListNode* newNode = new ListNode(1);
                tempAns->next = newNode;
                tempAns = newNode;
                carry= 0; 
            }
        }
        return ans->next;
    }
};