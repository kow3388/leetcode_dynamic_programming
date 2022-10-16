#include <bits/stdc++.h>

using namespace std;

//想不到
int maxProfit(vector<int> &prices, int fee)
{
    const int n = prices.size();
    int sell = 0, buy = -prices[0];

    for(int i = 1; i < n; i++)
    {
        //在什麼時候賣最划算, 要考慮手續費
        sell = max(sell, buy+prices[i]-fee);
        //決定要不要買
        buy = max(buy, sell-prices[i]);
    }

    return sell;
}

int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int ans = maxProfit(prices, fee);

    cout << ans << endl;

    return 0;
}