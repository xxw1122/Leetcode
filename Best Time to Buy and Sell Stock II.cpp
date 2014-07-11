#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> &prices)
    {
        int profit=0;
        int pos=0;
        if(prices.size()<=1) return 0;
        while(pos<prices.size())
            {
                int cur;
                for(cur=pos+1;cur<prices.size();cur++,pos++)
                    {
                        if(prices[cur]>=prices[pos])
                            {
                                profit=profit+prices[cur]-prices[pos];
                            }
                        else
                            {
                                pos=cur;
                                break;
                            }
                    }
                pos=cur;
            }
        return profit;
    }

