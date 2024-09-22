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
    int getLen(ListNode* & head){
        ListNode* temp=head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* solve(ListNode* head, int k){
        if(head == NULL){
            return head;
        }

        //base case
        int len = getLen(head);
        if(k > len){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        int count = 0;
        while(count < k){
            forward = curr->next;
            curr->next = prev;
            count++;
            prev = curr;
            curr = forward;
        }

        if(forward != NULL){
            head->next = solve(forward, k);
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};
