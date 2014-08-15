#include<iostream>

int minPathSum(vector<vector<int> > &grid)
    {
        int m=grid.size(),n=grid[0].size();
        if(m<=0) return 0;
        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(j>0&&i>0) grid[i][j]=min(grid[i][j]+grid[i-1][j],grid[i][j]+grid[i][j-1]);
                        else if(i==0&&j>0) grid[i][j]=grid[i][j]+grid[i][j-1];
                        else if(i>0&&j==0) grid[i][j]=grid[i][j]+grid[i-1][j];
                    }
            }
        return grid[m-1][n-1];
    }