class Solution {
public:
    bool path(int i,int j,vector<vector<char>>& board, string word,int currIdx){
        
        if(currIdx==word.size()) return true;
        
        if(i<0 or i>=board.size() or j<0 or j>=board[i].size() or board[i][j]!=word[currIdx] )
            return false;
        char ch=board[i][j];
        board[i][j]='1';
        
        // calls
     bool isPath=path(i-1,j,board,word,currIdx+1) or
        path(i+1,j,board,word,currIdx+1) or
         path(i,j-1,board,word,currIdx+1) or
         path(i,j+1,board,word,currIdx+1);
        
        board[i][j]=ch;
        
        return isPath;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
     for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
          
            if(board[i][j]==word[0] and path(i,j,board,word,0)) return true;
        }
    }
        return false;
    }
};