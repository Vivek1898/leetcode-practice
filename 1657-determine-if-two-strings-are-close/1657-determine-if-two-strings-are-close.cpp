class Solution {
public:
    bool closeStrings(string word1, string word2) {
      vector<int> count1(26,0);
        vector<int> count2(26,0);  
        int n=word1.length();
        int m=word2.length();
        if(n!=m) return false;
        
        
         for(int i=0;i<n;i++)  {
            count1[word1[i]-'a']++;
            count2[word2[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if((count1[i]>0 and count2[i]==0) or (count1[i]==0 and count2[i]>0))
                return false;
        }
         sort(begin(count1),end(count1));
        sort(begin(count2),end(count2));
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])
                return false;
        }
        return true;
        
        
    }
};