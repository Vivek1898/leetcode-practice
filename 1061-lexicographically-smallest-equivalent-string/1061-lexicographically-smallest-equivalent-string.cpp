class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> table(26);
        for (int i = 0; i < 26; i++) { table[i] = 'a' + i; }
        for (int i = 0; i < s1.size(); i++) {
            int curr_min = table[s1[i]-'a'], curr_max = table[s2[i]-'a'];
            if (curr_max < curr_min) { swap(curr_min, curr_max); }
            for (int j = 0; j < 26; j++) {
                if (table[j] == curr_max) { table[j] = curr_min; }
            }
        }
        for (int i = 0; i < baseStr.size(); i++) { baseStr[i] = table[baseStr[i]-'a']; }
        return baseStr;
    }
};