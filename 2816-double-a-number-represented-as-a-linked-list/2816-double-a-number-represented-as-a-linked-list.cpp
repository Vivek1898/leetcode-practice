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
    
    int helper(ListNode* h) {
        if(h == NULL) {
            return 0;
        }
        int d = helper(h->next) + 2*h->val;
        h->val = d%10;
        
        return d/10; 
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int c = helper(head);
        if(c) {
            head = new ListNode(c,head);
        }
        return head;
    }
};