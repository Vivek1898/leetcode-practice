class Solution {
public:
// gcd(len(a),len(b)) and output the first prefix of this length from either of the strings.

    string gcdOfStrings(string a, string b) {
        return (a + b== b + a)  ? a.substr(0, gcd(a.length(), b.length())): "";
    }
};