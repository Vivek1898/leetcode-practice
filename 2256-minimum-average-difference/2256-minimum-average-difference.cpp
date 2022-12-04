class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        long long sum= accumulate(nums.begin(),nums.end(),0ll);
        
//         int res=INT_MAX;
//         int pre[nums.size()];
//          pre[0] = nums[0];
//     // Adding present element with previous element
//     for (int i = 1; i < nums.size(); i++)
//         pre[i] = pre[i - 1] + nums[i];
//         int lt=0;
//         int j=nums.size()-1;
//         for(int i=0;i<nums.size();i++){
//            int rt=pre[i]/(i+1);
//             if(j==0){
//                 lt=0;
//             }else{
//                  lt=(pre[j]-pre[i])/(j);
//             }
           
//            int ans=abs(rt-lt);
//             cout<<ans<<endl;
//           if(res<ans) res=i;
//            j--;
//             // cout<<pre[i]<<" and "<<i << j <<endl;
//             // j--;
     //   }
        
        long long temp = 0;
        int flag = INT_MAX;
        int ans = 0;
        int n = nums.size();
        for (int i=0;i<n;i++){
            temp+=nums[i];
            int a1 = temp/(i+1);
            int a2 =0;
                if((n-i-1)!=0){
                  a2=  (sum-temp)/(n-i-1);
                }else{
                   a2=0; 
                }
            int curr = abs(a1-a2);
            if (curr<flag){
                ans = i;
                flag = curr;
            }
        }
        return ans;
       
    }
};