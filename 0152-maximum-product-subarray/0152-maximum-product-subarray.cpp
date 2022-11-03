class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int p1=nums[0];
        int p2=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int copy=max({nums[i],nums[i]*p1,nums[i]*p2});
            p2=min({nums[i],nums[i]*p1,nums[i]*p2});
                p1=copy;
            ans=max(ans,p1);
        
        }
        return ans;
    }
};