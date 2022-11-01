class Solution {
public:
    bool canJump(vector<int>& nums) {
          int n = nums.size();
    int goodPos = n - 1;
        cout<<n<<" ->Goosd"<<endl;
        cout<<n-2<<" ->sz"<<endl;
    // it over 2nd last position
    for (int i = n - 2; i >= 0; i--)
    {
      // Logic
      if (i + nums[i] >= goodPos)
         
      { 
          cout<<i+nums[i]<<endl;
       cout<<goodPos<<"gd"<<endl;
        goodPos = i;
         
      }
    }

    if (goodPos == 0)
      return true;
    else
      return false;
    }
};