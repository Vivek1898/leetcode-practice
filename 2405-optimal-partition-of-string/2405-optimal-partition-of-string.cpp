class Solution {
public:
    int partitionString(string s) {
        int number=0;
        int i=0,j=0;
        int si = s.length();
        string curr="";
        while(i<si)
        {
            if(curr.find(s[i])!=string::npos)
            { 
               number++;
                curr="";
                
            }
            else{
                curr+=s[i];
               i++;
            }
            
        }
        return number+1;
    }
};