class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord)
                return step;
            for(int i=0;i<word.size();i++)
            {
                char a=word[i];
                for(char b='a';b<='z';b++)
                {
                    word[i]=b;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=a;
            }
        }
        return 0;
    }
};