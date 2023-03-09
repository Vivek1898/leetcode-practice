class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head ;
        ListNode *fast = NULL ;
        bool firstly=true ;
        while(slow!=fast){
            if(firstly){
                fast=head ;
                firstly = false; 
            }
            if(slow==NULL || fast==NULL || fast->next==NULL || fast->next->next==NULL){
                return NULL ;
            }
            slow = slow->next ;
            fast = fast->next->next ;
        }
        slow=head ;
        while(slow!=fast){
            slow = slow->next ;
            fast = fast->next ;
        }
        return slow ;
    }
};