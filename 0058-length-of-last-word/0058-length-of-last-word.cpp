class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end()); //reversing the string so that the last word of the string can be accessed first
        int cnt = 0, flag = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != ' ')
            {
                flag = 1; //this warns about the first occurance of the non-space char(i.e starting of the first word)
                cnt++; //this counts the number of the chars in the word
            }
            else if(flag == 1 && s[i] == ' ') //this checks if that the current iteration is not the first space char(i.e some non-space chars are already before this because the flag is 1)
            {
                break;
            }
        }
        return cnt;
    }
};