class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=0,p=0,o=0;
        for(auto x:nums){
            if(x<0) n++;
            if(x==0) o++;
            if(x>0) p++;
            
        }
       // cout<<n<<" "<<p<<" "<<o<<endl;
        int ans=0;
           if(o>0) ans=0;
        else if(n&1) ans=-1;
        else ans=1;
        
        return ans;
        
        
    }
};