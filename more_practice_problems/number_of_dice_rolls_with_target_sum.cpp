#include <bits/stdc++.h>

using namespace std;

//想不到
int numRollsToTarget(int n, int k, int target)
{
    constexpr int kmod = 1e9 + 7;
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1;

    //擲第幾顆骰子
    for(int i = 1; i <= n; i++)
        //骰子的範圍
        for(int j = 1; j <= k; j++)
            //從1~target可以有幾種方式表現
            for(int l = j; l <= target; l++)
                //想法和coin change相似
                //骰子為j，則看少一顆骰子數值-j有多少種方式
                dp[i][l] = (dp[i][l] + dp[i-1][l-j]) % kmod;

    return dp[n][target];
}

int main()
{
    int n = 30, k = 30, target = 500;
    int ans = numRollsToTarget(n, k, target);

    cout << ans << endl;

    return 0;
}