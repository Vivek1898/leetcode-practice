class NumMatrix 
{
public:
    //Here, we use prefix sum approach
    //in which we store the sum of all the cells in rows and columns till current cell
    
    //initialize sum for storing prefix-sum
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int r=matrix.size(), c=matrix[0].size();
        sum = vector<vector<int>> (r+1, vector<int> (c+1));
        
        //storing sum by adding (upper cell, left cell, and current cell value) and subtracting (row-1)(col-1) cell value
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];  
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        row1++, col1++, row2++, col2++;
        //you can understand this logic through the image attached
        return sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];        
    }
};