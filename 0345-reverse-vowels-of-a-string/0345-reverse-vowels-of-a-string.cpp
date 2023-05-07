class Solution
{
public:
    string reverseVowels(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'};
        while (l < r)
        {
            //   cout<<s[l] <<"->"<<s[r]<<endl;
            if (v.count(s[l]) and v.count(s[r]))
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            else if (v.count(s[l]))
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return s;
    }
};