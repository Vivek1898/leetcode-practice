class Solution {
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        auto dummy = new ListNode(-1);
        
        auto ptr = dummy;
        
        auto curr1 = list1;
        auto curr2 = list2;
        
        while(curr1 and curr2){
            if(curr1->val > curr2->val){
                ptr->next = curr2;
                curr2 = curr2->next;
            }
            else{
                ptr->next = curr1;
                curr1 = curr1->next;
            }
            ptr = ptr->next;
            
            
        }
        ptr->next = (curr1) ? curr1 : curr2;
            
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        ListNode* ptr = NULL;

        if(n > 0 && lists[0]){
            ptr = lists[0];
        }

        for(int i=1;i<n;i++){
            ListNode* startPtr = mergeTwoLists(ptr, lists[i]);
            ptr = startPtr;
        }
        return ptr;
    }
};