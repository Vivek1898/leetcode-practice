class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        int st = 0;
        while(st<n && sat[st]<0) st++;

        int ans = 0;
        int sum = 0;
        for(int i=st; i<n; i++){
            ans+= sat[i]*(i-st+1);
            sum+= sat[i];
        }

        // cout<<st<<" "<<ans<<endl;
        st--;
        while(st>=0 && sat[st]+sum>=0){
            sum+=sat[st];
            ans+=sum;
            // cout<<st<<" "<<sum<<" "<<ans<<endl;
            st--;
        }

        return ans;
    }
};