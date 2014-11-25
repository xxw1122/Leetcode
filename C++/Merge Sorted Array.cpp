#include<iostream>

void merge(int A[], int m, int B[], int n)
    {
        int *arry=new int[m+n];
        int i=0,j=0,k=0;
        while(i<m&&j<n)
            {
                if(A[i]<=B[j])
                    {
                        arry[k++]=A[i];
                        i++;
                    }
                else
                    {
                        arry[k++]=B[j];
                        j++;
                    }
            }
        while(i==m&&j<n)
            {
                arry[k++]=B[j++];
            }
        while(j==n&&i<m)
            {
                arry[k++]=A[i++];
            }
        for(i=0;i<m+n;i++)
            A[i]=arry[i];
        delete [] arry;
    }