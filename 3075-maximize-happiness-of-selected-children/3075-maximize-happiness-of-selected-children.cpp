class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end(),greater<long long >());
        long long  sum=0;
        long long ans=0;
        for(long long  i=0;i<k;i++){
            if(i==0 and h[i]>0){
                sum+=h[i];
                ans=max(ans,sum);
                continue;
            }
            if(h[i] > 0 and sum > 0){
                sum+=h[i];
                if(h[i]==1 )
                    sum-=1;
                else 
                sum-=i;
            }
            ans=max(ans,sum);
        }
        return ans;

    }
};