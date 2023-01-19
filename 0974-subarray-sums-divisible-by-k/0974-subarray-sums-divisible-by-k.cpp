class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
//         int n=a.size();
//  int cnt=0;
//   for(int i=0;i<n;i++){
//       int sum=0;
//       for(int j=i;j<n;j++){
           
//           sum+=a[j];
//          // cout<<abs(sum)<<"sum\n";
//           if(sum%k==0 or sum==0) {
              
//               cnt++;
//           }
//       }
//   }

//   return cnt;
           int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        for(int i = 0; i<n; i++) {
            currSum = (currSum + nums[i]%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;
    }
};