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
stack<int> st;
        
        ListNode *curr = head;
        
        while(curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        
        int maxTwinVal = 0;
        int size = st.size();
        int count = 1;
        while(count++ <= size/2) {
            maxTwinVal = max(maxTwinVal , st.top() + head->val);
            st.pop();
            head = head->next;
        }
        
        return maxTwinVal;
}
};