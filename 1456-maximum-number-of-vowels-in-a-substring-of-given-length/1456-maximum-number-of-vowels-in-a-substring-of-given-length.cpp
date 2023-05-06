class Solution {
public:
    int maxVowels(string s, int k) {
         int n = s.size();
        int left = 0, right = 0;
        int maxVowels = 0, currVowels = 0;
        unordered_set<char> vw = {'a', 'e', 'i', 'o', 'u'};
        
        while(right<n){
            if(vw.count(s[right])) currVowels++;
            
            if(right-left+1>k){
                if(vw.count(s[left])) currVowels--;
                left++;
            }
            maxVowels=max(maxVowels,currVowels);
            right++;
        }
        return maxVowels;
        
        
    }
};