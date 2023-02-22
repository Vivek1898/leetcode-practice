class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        int dir=0;
        int t=0;
        int b=m.size()-1;
        int l=0;
        int i;
        int r= m[0].size()-1;
        vector<int>ans;
        while(l<=r and t<=b){
            if(dir==0){
                for( i=l;i<=r;i++)
                ans.push_back(m[t][i]);
                  t++;
            }else if(dir==1){
                for( i=t;i<=b;i++){
                    ans.push_back(m[i][r]);
                }
                r--;
            }else if(dir==2){
                for( i=r;i>=l;i--){
                    ans.push_back(m[b][i]);
                   
                }
                 b--;
            }else if(dir==3){
                 for( i=b;i>=t;i--){
                    ans.push_back(m[i][l]);
                }
                l++;
            }
             dir=(dir+1)%4;
        }
        return ans;
    }
};