class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can=0;
        
        int count=0;
        for(auto it :nums){
            if(count == 0) {
                can=it;
            }
            if(it==can) count++;
            else count-- ;
            
        }
        
        return can;
    }
};