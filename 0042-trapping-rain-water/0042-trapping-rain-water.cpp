class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
       int l[n];
        int r[n];
        
     l[0]=h[0];
        
        for(int i=1;i<n-1;i++){
            l[i]=max(h[i],l[i-1]);
        }
        
        r[n-1]=h[n-1];
        
        for(int i=n-2;i>=0;i--){
            r[i]=max(h[i],r[i+1]);
        }
        
        int res=-1+1;
        for(int i=1;i<n-1;i++){
        int t= min(l[i],r[i]);
            
        res+=t-h[i];
            
            
        }
    return res;    
    }
    
};