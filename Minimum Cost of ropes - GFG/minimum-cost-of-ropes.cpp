//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
     //   vector<int>ans;
        long long ans=0;
        long long temp=0;
        while(pq.size()>1){
             temp=pq.top();
            pq.pop();
            temp+=pq.top();
            pq.pop();
            ans+=temp;
            pq.push(temp);
            }
            return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends