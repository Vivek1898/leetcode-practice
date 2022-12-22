class Solution {
public:
    int specialArray(vector<int>& v) {
        int low=1,high=100,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2,cnt=0;
            for(auto c:v)if(c>=mid)cnt++;
            if(cnt==mid){
                ans=mid;
                low=mid+1;
            }

            if(cnt>mid)low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};
