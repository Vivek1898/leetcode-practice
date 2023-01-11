//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    // int count(int arr[],int mid,int n){
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         if(arr[i]<mid) cnt++;
    //     }
    //     return cnt;
    // }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
       // sort(arr,arr+r+1);
      // while()
      //  return arr[k-1];
      int low=*min_element(arr,arr+r);
      int high=*max_element(arr,arr+r);
      int ans=-1;
      while(low<high){
          int mid =low+(high-low)/2;
          int cnt=0;
          for(int i=0;i<r+1;i++){
              if(arr[i]<=mid) cnt++;
          }
          
          if(cnt<k){
           //   ans=mid;
              low=mid+1;
          }else{
              high=mid;
          }
      }
      return low;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends