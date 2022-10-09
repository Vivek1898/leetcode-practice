#include<vector>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      //  int one[256]={0};
       //  int two[256]={0};
      //  vector<int>one(26,0);
     //   vector<int>two(26,0);
         unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int m=s.length();
        int n=s.length();
        if(n!=m)return false;
        
        for(int i=0;i<n;i++){
           map1[s[i]] = i+1;
            map2[t[i]] = i+1;
        }
        
          for(int i=0;i<n;i++){
         if(map1[s[i]]!=map2[t[i]]) return false;
        }
        return true;
        
    }
};