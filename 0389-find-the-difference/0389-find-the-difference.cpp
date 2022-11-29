class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> v(26);
		for(int i=0;i<s.length();i++) {
			v[s[i]-'a']++;
		}
		for(int i=0;i<t.length();i++) {
			v[t[i]-'a']--;
			if(v[t[i]-'a']==-1) return t[i];
		}
		return '0';
	}
};