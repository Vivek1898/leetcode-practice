class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         int window = s1.size(), lenS2 = s2.size();
        if (window > lenS2) return false;

        vector<int> countS1(26, 0), countS2(26, 0);
        for (int i = 0; i < window; ++i) {
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }
        if (countS1 == countS2) return true;
        for (int i = window; i < lenS2; ++i) {
            countS2[s2[i] - 'a']++;
            //exclude
            countS2[s2[i - window] - 'a']--;
            if (countS1 == countS2) return true;
        }
        return false;
    }
};