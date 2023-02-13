class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int left[n];
        int right[n];
        
        left[0]=1;
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
            // cout<<left[i] << " ";
        }
        
        right[n-1]=1;
        
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
          //  cout<<right[i] << " ";
        }
        for(int i=0;i<n;i++){
             cout<<right[i] << " ";
        }
        cout<<endl;
          for(int i=0;i<n;i++){
             cout<<left[i] << " ";
        }
        
         for(int i=0;i<n;i++){
            nums[i]=left[i]*right[i];
        }
        return nums;
    }
};