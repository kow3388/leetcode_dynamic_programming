#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> cnt(amount+1, INT_MAX);
    cnt[0] = 0;

    for(const auto coin : coins)
        for(int i = coin; i <= amount; i++)
            if(cnt[i-coin] != INT_MAX)
                cnt[i] = min(cnt[i], cnt[i-coin]+1);

    return cnt[amount] == INT_MAX? -1 : cnt[amount];
}

int main()
{
    vector<int> coin = {1,2,5};
    int amount = 11;
    int ans = coinChange(coin, amount);

    cout << ans << endl;

    return 0;
}