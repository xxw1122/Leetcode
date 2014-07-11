#include<iostream>

void sortColors(int A[],int n)
    {
        int left=0,right=n-1;
        int pos=0,temp;
        while(left<right&&pos<=right)
            {
                if(A[pos]==0)
                    {
                        if(pos==left)
                        {
                            left++;
                            pos++;
                            continue;
                        }
                        temp=A[pos];
                        A[pos]=A[left];
                        A[left]=temp;
                        left++;
                    }
                else if(A[pos]==2)
                    {
                        if(pos==right)
                        {
                            right--;
                            pos++;
                            continue;
                        }
                        temp=A[pos];
                        A[pos]=A[right];
                        A[right]=temp;
                        right--;
                    }
                else pos++;
            }
    }