#include <bits/stdc++.h>

using namespace std;

int change(int amount, vector<int> &coins)
{
    const int n = coins.size();
    vector<int> way(amount+1, 0);
    way[0] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 1; j <= amount; j++)
            if(i == 0)
            {
                if(j % coins[i] == 0)
                    way[j] = 1;
            }
            else
            {
                if(way[j-coins[i]] != INT_MAX)
                    way[j] += way[j-coins[i]];
            }
    
    return way[amount];
}

int main()
{
    vector<int> coins = {1,2,5};
    int amount = 5;
    int ans = change(amount, coins);

    cout << ans << endl;

    return 0;
}