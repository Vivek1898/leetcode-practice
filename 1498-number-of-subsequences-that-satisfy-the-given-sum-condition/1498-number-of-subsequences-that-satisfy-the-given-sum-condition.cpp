class Solution {
public:
    int mod = 1e9 + 7;

long long power(long long x, long long y) {
    if (y == 1) return x;
    if (y == 0) return 1;
    long long ans = 1;
    if (y % 2 == 0) {
        ans = power(x, y / 2);
        ans *= ans;
    } else {
        ans = power(x, y - 1);
        ans *= x;
    }
    return ans % mod;
}
    
    
    int numSubseq(vector<int>& nums, int target) {
        
        //brute
        sort(nums.begin(),nums.end());
        
      int high=nums.size()-1;
     int low=0;
        int ans=0;
        
        while(low<=high){
            //long ans=;
            if(nums[low]+nums[high]<=target){
                 ans+=power(2,high-low);
                ans%=mod;
                  low++;
            }
            else
            high--;
        }
        
        return ans%mod;
        
    }
};