class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Rob houses from 
        // 0 to n-2 and 
        // 1 to n-1
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(memo(0, nums, dp1, n-1), memo(1, nums, dp2, n));
    }

private:
    int memo(int i, vector<int>& v, vector<int>& dp, int end) {
        if (i >= end) return 0;
        if (dp[i] != -1) return dp[i];

        int robAndMove = v[i] + memo(i + 2, v, dp, end);
        int move = memo(i + 1, v, dp, end);
        
        return dp[i] = max(robAndMove, move);
    }
};