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
    vector<int> v;//created vector to store linked list elements
    Solution(ListNode* head) {
        ListNode *temp = head;

        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int n = v.size();
//using rand() to get random numbers
//And dividing random no. by n to get a number in range 0 - (n-1).

        int x = rand()%n;

       
        return v[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */