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
    ListNode* swapNodes(ListNode* head, int k) {
         ListNode* lt=head;
         ListNode* rt=head;
        int i=0;
        while(i<k-1){
            rt=rt->next;
            i++;
        }
        
         ListNode* en=rt;
        while(rt->next){
            lt=lt->next ;
            rt=rt->next;
        }
        swap(en->val,lt->val);
        return head;
        
    }
};