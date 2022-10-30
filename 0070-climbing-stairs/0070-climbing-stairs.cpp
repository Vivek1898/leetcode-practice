class Solution {
public:
    //Move 1 and 2
    //recursive
    void helper(int n,int &ans){
        if(n==0){
            ans+=1;
        }
        if(n<0) return;
        
        helper(n-1,ans);
        
         helper(n-2,ans);
 }
    
    
    int climbStairs2(int n) {
        int ans=0;
        
        helper(n,ans);
        
      return ans;
        
    }
    
    
      int climbStairs(int n) {
        int arr[n+1];
           arr[0]=1;
          arr[1]=1;
          
          for(int i=2;i<=n;i++){
              arr[i]=arr[i-1]+arr[i-2];   
          }
        
      return arr[n];
        
    }
   
};