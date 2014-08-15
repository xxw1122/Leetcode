#include<iostream>
#include<vector>

void setZeroes(vector<vector<int> > &matrix)
    {
        int cnt=-1;
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(matrix[i][j]==0)
                            {
                                for(int k=0;k<m;k++)
                                    {
                                        if(matrix[k][j]!=0) matrix[k][j]=cnt;
                                    }
                                for(int k=0;k<n;k++)
                                    {
                                        if(matrix[i][k]!=0) matrix[i][k]=cnt;
                                    }
                            }
                    }
            }
        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(matrix[i][j]==cnt) matrix[i][j]=0;
                    }
            }
        return;
    }