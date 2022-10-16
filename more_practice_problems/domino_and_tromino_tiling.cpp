#include <bits/stdc++.h>

using namespace std;

//想不到
int numTilings(int n)
{
    constexpr int kmod = 1e9 + 7;
    vector<vector<long>> dp(n+1, vector<long>(3, 0));
    //col 0 和 1的情況只有一種
    dp[0][0] = dp[1][0] = 1;

    for(int i = 2; i <= n; i++)
    {
        //太難用文字描述
        /*
        dp[i][0]樣子
        ***
        ***
        dp[i][1]樣子
        ***
        **
        dp[i][2]樣子
        **
        ***
        */
        //https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-790-domino-and-tromino-tiling/
        dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % kmod;
        dp[i][1] = (dp[i-2][0] + dp[i-1][2]) % kmod;
        dp[i][2] = (dp[i-2][0] + dp[i-1][1]) % kmod;
    }

    return dp[n][0];
}

int main()
{
    int n = 3;
    int ans = numTilings(n);

    cout << ans << endl;

    return 0;
}