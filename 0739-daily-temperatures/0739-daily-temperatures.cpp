// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& t) {
//         vector<int>ans(t.size(),0);
//         for(int i=1;i<t.size();i++){
//             if(t[i-1]<=t[i]){
//                // cout<<t[i-1];
//                 ans.push_back(1);
//             }else{
//                 int currmax=t[i-1];
//               //  cout<<currmax<<endl;
//                 int fs=i;
//                // cout<<currmax<<" ";
//                 for(int j=i+1;j<t.size();j++){
//                     if(t[j]>currmax) {
//                         fs=j;
//                         break;
//                     }
                    
//                 }
               
//                 cout<<endl;
//                 cout<<fs<<" and "<<i;
//                   cout<<endl;
//                 int pb=fs-i;
//                 ans.push_back(pb);
                
//             }
//             // cout<<i;
            
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for(int i = n - 1; i >= 0; i--){
            int curr = temperatures[i];
            int dist = 0;
            for(int j = i + 1; j < n; ){
                if(curr < temperatures[j]){
                    dist = j - i;
                    break;
                }
                if(answer[j] == 0) break;
            
                j = j + answer[j];   
            }
            answer[i] = dist;
        }
        return answer;
    }
};