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
        if(head == nullptr or head->next == nullptr) {
            return head;
        }
        ListNode* nextNode = removeNodes(head->next);
        if(nextNode->val > head->val) {
            return nextNode;
        }
        head->next = nextNode;
        return head;
    }
};