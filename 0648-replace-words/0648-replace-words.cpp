class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    string h="",ans="";
    sort(dictionary.begin(),dictionary.end());
    sentence+=" ";
    for(auto it:sentence){
        if(it==' '){
            bool op=1;
            for(auto r:dictionary){
                if(h.size()>r.size() and h.substr(0,(int)r.size())==r){
                    ans+=r;
                    op=0;
                    break;
                }
            }
            if(op) ans+=h;
            h="";
            ans+=" ";
        } else{
            h+=it;
        }
    }
    ans.pop_back();
    return ans;   
    }
};