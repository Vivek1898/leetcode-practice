class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        
        int total=accumulate(arr.begin(),arr.end(),0);
        if(total%3!=0) return false;
        int parts=total/3;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==parts){
                ans++;
                sum=0;
            }
            
        }

       return ans>=3;
        
    }
};