#include<iostream>
#include<vector>

void rotate(vector<vector<int> > &matrix)
    {
        int num=matrix.size();
        if(num==0) return;
        int cnt;
        for(int i=0;i<num;i++)
            {
                for(int j=i+1;j<num;j++)
                    {
                        cnt=matrix[i][j];
                        matrix[i][j]=matrix[j][i];
                        matrix[j][i]=cnt;
                    }
            }
        for(int i=0;i<num/2;i++)
            {
                for(int j=0;j<num;j++)
                    {
                        cnt=matrix[j][i];
                        matrix[j][i]=matrix[j][num-1-i];
                        matrix[j][num-1-i]=cnt;
                    }
            }
    }