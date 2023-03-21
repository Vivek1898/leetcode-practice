class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long prevCnt = 0;

        for (int& num: nums) {
            if (num != 0) {
                prevCnt = 0;
            }
            else {
                ans += prevCnt + 1;
                prevCnt++;
            }
        }

        return ans;
    }
};