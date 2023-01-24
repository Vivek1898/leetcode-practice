//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>mp;
    
    int slowWinStart=0;
    int maxLen=0;
    for(int fastEnd=0;fastEnd<s.size();fastEnd++){
        char RightChar=s[fastEnd];
        mp[RightChar]++;
        while((int)mp.size()>k){
            char LeftChar=s[slowWinStart];
            mp[LeftChar]--;
            if(mp[LeftChar]==0) mp.erase(LeftChar);
            slowWinStart++;
        }
        maxLen=max(maxLen,fastEnd-slowWinStart+1);
        
    }
    if(k>s.size() || k>mp.size() ) maxLen=-1; 
    
    return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends