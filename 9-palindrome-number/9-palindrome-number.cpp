class Solution {
public:
    bool isPalindrome2(int x) {
    string convertedNumber = to_string(x);
 
    string reverseString = convertedNumber;
    reverse(reverseString.begin(),reverseString.end());
    return reverseString == convertedNumber ? true : false;
    }
     bool isPalindrome(int n) {
 long long    int reverse = 0;
    long long int temp = n;
    if(n<0) return 0;
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse
            == n); // if it is true then it will return 1;
                   // else if false it will return 0;
    }


    
};