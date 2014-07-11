#include<iostream>
#include<vector>

using namespace std;


int maxProfit(vector<int> &prices)
    {
        if(prices.size()==0) return 0;
        int minv=prices[0],maxv=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
            {
                if(prices[i]-minv>profit) profit=prices[i]-minv;
                if(prices[i]<minv) minv=prices[i];
            }
        return profit;
    }