class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        map<int,int>m;
        int slow=0;
        int repeat=0;
        int len=0;
        for(int f=0;f<nums.size();f++){
         //   m[nums[f]]++;
            if(nums[f]==1) repeat++;
         //   repeat=max()
            
            while(f-slow+1 - repeat >k){
               if(nums[slow++]==1) repeat--;
            }
            len=max(len,f-slow+1);
        }
        return len;
    }
};