#include <bits/stdc++.h>

using namespace std;

//想不到
int maxProfit(int k, vector<int> &prices)
{
    const int n = prices.size();
    //k+1是為了對齊
    vector<int> balance(k+1, INT_MIN);
    vector<int> profit(k+1, 0);

    for(int i = 0; i < n; i++)
        for(int j = 1; j <= k; j++)
        {
            //balance[j]在i天做j次買(可以持有一張股票)，且決定在第i天要不要買
            //可以理解為在第幾天買最划算
            balance[j] = max(balance[j], profit[j-1] - prices[i]);
            //profit[j]在i天內做j次sell(不能hold)的最大收益
            //可以理解為在哪一天賣最划算
            profit[j] = max(profit[j], balance[j]+prices[i]);
        }

    return profit[k];
}

int main()
{
    int k = 3;
    //{-1, 3, 1, -6, 3}
    vector<int> prices = {3,2,5,6,0,3};
    int ans = maxProfit(k, prices);

    cout << ans << endl;

    return 0;
}