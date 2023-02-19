//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int idx=-1;
    int idx2=-1;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==x and flag==false){
            idx=i;
            flag=true;
        }else if(arr[i]==x and arr[i]!=arr[i+1]){
            idx2=i;
        }
    }
    
    if(idx2==-1) idx2=idx;
    return {idx,idx2};
    
    // code here
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends