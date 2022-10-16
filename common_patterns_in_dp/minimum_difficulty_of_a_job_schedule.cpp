#include <bits/stdc++.h>

using namespace std;

//寫不出來
//難度: hard
int minDifficulty(vector<int> &jobDifficulty, int d)
{
    const int n = jobDifficulty.size();
    if(d > n)
        return -1;
    
    vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i - 1, md = 0; j >= 0; j--)
        {
            md = max(md, jobDifficulty[j]);
            for(int k = 1; k <= min(i, d); k++)
                //dp[i][k] => 表示在k天內處理掉i個job
                //dp[i][k]可以表示成dp[j][k-1] + md
                //k-1天處理j個job再加一天處理的job
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + md);
        }

    return dp[n][d];
}

int main()
{
    vector<int> jobDifficulty = {11,111,22,222,33,333,44,444};
    int d = 6;
    int ans = minDifficulty(jobDifficulty, d);

    cout << ans << endl;

    return 0;
}