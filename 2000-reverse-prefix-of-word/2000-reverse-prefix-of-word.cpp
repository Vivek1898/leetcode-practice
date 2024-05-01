class Solution {
private:
    void solve(string& word, int s, int e) {
        if (s >= e) {
            return;
        }
        swap(word[s], word[e]);
        solve(word, s + 1, e - 1);
    }

public:
    string reversePrefix(string word, char ch) {
        int end = word.size();
        for (int i = 0; i < end; i++) {
            if (word[i] == ch) {
                end = i;
                break;
            }
        }
        if(end == word.size()){
            return word;
        }
        solve(word, 0, end);
        return word;
    }
};