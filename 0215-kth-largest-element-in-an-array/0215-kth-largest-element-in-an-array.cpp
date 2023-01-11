class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
   int low=*min_element(arr.begin(),arr.end());
      int high=*max_element(arr.begin(),arr.end());
      int ans=1;
      while(low<=high){
          int mid =low+(high-low)/2;
          int cnt=0;
          for(int i=0;i<arr.size();i++){
              if(arr[i]>=mid) cnt++;
          }
          // if(arr.size()==1){
          //     return ans;
          // }else
           if(cnt>=k){
             // ans=mid;
              low=mid+1;
          }else{
              high=mid-1;
          }
      }
      //  arr.size()==1? ans:
      return  low-1;
    }
};