#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    vector<int> profit;
    for(int i = 1; i < prices.size(); i++)
        profit.push_back(prices[i] - prices[i-1]);
    
    vector<int> record;
    record.push_back(profit[0]);
    int tmp_max = record[0];

    for(int i = 1; i < profit.size(); i++)
    {
        int val = max(record[i-1]+profit[i], profit[i]);
        record.push_back(val);
        tmp_max = max(tmp_max, val);
    }

    return tmp_max <= 0? 0 : tmp_max;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}