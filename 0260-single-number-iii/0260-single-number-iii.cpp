class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long val = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int first = 0, second = 0;
        val &= -val;
        for (int num : nums){
            if (num & val) second ^= num;
            else first ^= num;
        }
        return {first, second};
    }
};