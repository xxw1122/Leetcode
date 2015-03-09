class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        for(int i = 0; i < n-3; i++)
        {
            if(i > 0 && num[i] == num[i-1])continue;//防止第一个元素重复
            for(int j = i+1; j < n-2; j++)
            {
                if(j > i+1 && num[j] == num[j-1])continue;//防止第二个元素重复
                int target2 = target - num[i] - num[j];
                int head = j+1, tail = n-1;
                while(head < tail)
                {
                    int tmp = num[head] + num[tail];
                    if(tmp > target2)
                        tail--;
                    else if(tmp < target2)
                        head++;
                    else
                    {
                        res.push_back(vector<int>{num[i], num[j], num[head], num[tail]});
                        //为了防止出现重复的二元组，使结果等于target2
                        int k = head+1;
                        while(k < tail && num[k] == num[head])k++;
                        head = k;

                        k = tail-1;
                        while(k > head && num[k] == num[tail])k--;
                        tail = k;
                    }
                }
            }
        }
        return res;
    }
};
