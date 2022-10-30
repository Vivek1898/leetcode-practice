class Solution {
public:
    //two pointer
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
       vector<int>res(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[r])>abs(nums[l])) res[i]=nums[r]*nums[r--];
            else res[i]=nums[l]*nums[l++];
        }
        return res;
    }
};