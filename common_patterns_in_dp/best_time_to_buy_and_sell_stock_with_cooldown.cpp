#include <bits/stdc++.h>

using namespace std;

//想不到
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    //三個state，rest, hold, sold
    //rest -> buy -> hold
    //hold -> sell -> sold
    //sold -> cooldown -> rest
    //rest是賣完後的冷卻時間，可以想成前一個時間點前的
    int sold = 0, rest = 0;
    int hold = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int prev_sold = sold;
        //假設麥的話會是多少profit
        sold = hold + prices[i];
        //決定要不要買
        hold = max(hold, rest - prices[i]);
        //決定要不要賣
        rest = max(rest, prev_sold);
    }

    return max(rest, sold);
}

int main()
{
    vector<int> prices = {1,2,3,0,2};
    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}