class Solution {
public:
    int candy(vector<int>& r) {
        int ans = 0, n= r.size();
        
       
        vector<int>prefix(n,1);
        for(int i=1; i<n; i++){
            if(r[i]>r[i-1] )
                prefix[i]=prefix[i-1]+1;
        }
        
      
        vector<int> suffix(n,1);
        for(int i=n-2; i>=0; i--){
            if(r[i]>r[i+1] )
                suffix[i] = suffix[i+1]+1;
        }
        
//         for(int i=0;i<n;i++){
//             cout<<prefix[i]<<" ";
            
//         }
//         cout<<endl;
//          for(int i=0;i<n;i++){
//             cout<<suffix[i]<<" ";
            
//         }
//         cout<<endl;
        
        
       
        for(int i=0; i<n; i++){
            ans += max(prefix[i], suffix[i]);
        }
        
        return ans;
    }
};