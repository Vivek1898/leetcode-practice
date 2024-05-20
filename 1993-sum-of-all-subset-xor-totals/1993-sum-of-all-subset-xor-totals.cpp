class Solution {
public:
   void helper(vector<int>& nums, vector<int>& ans , int &total , int i)
   {
     
       if(i==nums.size())
       {
           int Xor=0;
           for(int j=0;j<ans.size();j++)
           {
               Xor^=ans[j];
           }
           total+=Xor;
           return;

       }
        helper(nums,ans,total,i+1);
        
        ans.push_back(nums[i]);
        helper(nums,ans,total,i+1);

        ans.pop_back(); 

   }
    int subsetXORSum(vector<int>& nums) {
      vector<int> ans;
      int total=0;
      int i=0;
      helper(nums,ans,total,i); 
      
      return total;
    }
};