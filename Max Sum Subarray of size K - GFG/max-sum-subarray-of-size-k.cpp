//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int n){
        // code here 
         int ws = 0;
         int we = 0;
         long long ans = 0;
         long long sum = 0;
         while(we<n)
         {
             sum+=a[we];
             if(we-ws+1==k){
                 ans=max(sum,ans);
             }else if(we-ws+1>k){
                 while(we-ws+1>k)
                 {
                     sum-=a[ws];
                     ws++;
                 }
                 ans = max(ans,sum);
                 
             }
             we++;
         }
         return ans;
    
    // return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends