//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int n){
        // code here 
        long curr=0;
    for(long int i=0;i<k;i++){
        curr+=a[i];
        
    }
   long int mx=curr;
    for(long int i=k;i<n;i++){
        long int ax=a[i];
        long int m=a[i-k];
       curr+=ax-m;
        mx=max(mx,curr);
    }
    return mx;
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