class Solution {
public:
    int minMoves(vector<int>& nums) {
       
        int sum=accumulate(nums.begin(),nums.end(),0);
        int small=*min_element(nums.begin(),nums.end());
        
        int ans=sum-(nums.size()*small);
        return ans;
    }
};