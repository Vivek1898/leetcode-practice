class Solution {
public:
    
     int longestKSubstr(vector<int> s, int k)
    {
        // your code here

        unordered_map<int, int> m;
        int i = 0, j = 0;
        int ans = 0;
        while (i < s.size())
        {
            m[s[i]]++;
            // Acquire
          
            if (m.size() > k)
            {
                // Release
                  while(m.size() > k){
                    m[s[j]]--;
                    if (m[s[j]] == 0)
                    {
                        m.erase(s[j]);
                    }
                    j++;
                  }
                
               
            }
              ans += (i-j+1);
             i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return longestKSubstr(nums,k) -longestKSubstr(nums,k-1);
    }
};