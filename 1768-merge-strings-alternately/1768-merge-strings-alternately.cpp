class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str;
        int size= word1.length()>word2.length()?word1.length():word2.length();

        for(int i=0;i<size;i++)
        {
            if(i<word1.length())
            str+=word1[i];

            if(i<word2.length())
            str+=word2[i];
                
        }
        return str;
        
        
    }
};