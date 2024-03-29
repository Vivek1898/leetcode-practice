/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int isUniform(vector<vector<int>> grid, int sr, int sc, int er, int ec){
        unordered_set<int> s;
        int c = -1;
        for(int i = sr; i <= er; i++)
            for(int j = sc; j <= ec; j++){
                c = grid[i][j];
                s.insert(grid[i][j]);
            }
        return (s.size() > 1)?-1:c;    
    }
    Node * solve(vector<vector<int>>& grid, int m, int n, int o, int p){
        Node *ans = new Node();
        int m1 = (m+o)/2;
        int m2 = (n+p)/2;
        
        if(m == o && n == p){
            ans->val = grid[0][0];
            ans->isLeaf = 1;
            return ans;
        }
        //m to mid, mid+1 to n
        int tl = isUniform(grid, m, n, m1, m2);
        int tr = isUniform(grid, m, m2+1, m1, p);
        int bl = isUniform(grid, m1+1, n, o, m2);
        int br = isUniform(grid, m1+1, m2+1, o, p);

        cout<<tl<<" "<<tr<<" "<<bl<<" "<<br<<endl;

        if(tl >= 0 && tr >= 0 && bl >= 0 && br >= 0 && tl == tr && tr == bl && bl == br && br == tl){
            ans = new Node(tl, 1);
        }else{

            if(tl != -1){
                ans->topLeft = new Node(tl, 1);
            }else{
                ans->isLeaf = 0;
                ans->topLeft = solve(grid, m, n, m1, m2);
            }
            if(tr != -1){
                ans->topRight = new Node(tr, 1);
            }else{
                ans->isLeaf = 0;
                ans->topRight = solve(grid, m, m2+1, m1, p);
            }
            if(bl != -1){
                ans->bottomLeft = new Node(bl, 1);
            }else{
                ans->isLeaf = 0;
                ans->bottomLeft = solve(grid, m1+1, n, o, m2);
            }
            if(br != -1){
                ans->bottomRight = new Node(br, 1);
            }else{
                ans->isLeaf = 0;
                ans->bottomRight = solve(grid, m1+1, m2+1, o, p);
            }
        }
        return ans;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        Node *ans = solve(grid, 0, 0, n-1, n-1);
        return ans;
    }
};
