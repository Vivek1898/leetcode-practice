class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        int n=p.size()-1;
        int i=0 , j=n;
        int ans=0;
        sort(p.begin(),p.end());
        
        while(i<=j){
            if(p[i]+p[j] <= limit){
                i++;
                j--;
            }else{
                 j--;
            }
           
            ans++;
           
        }
        return ans;
        
    }
};