#include <bits/stdc++.h>

using namespace std;

//a後面只能是e
//e後面可以是a or i
//i後面不能是i
//o後面可以是i or u
//u後面只能是a
//hard不重要
int countVowelPermutation(int n)
{
    constexpr int kMod = 1e9 + 7;
    vector<vector<long>> dp(n + 1, vector<long>(5));
    fill(begin(dp[1]), end(dp[1]), 1);
    // 0: a, 1: e, 2: i, 3: o, 4: u
    for (int i = 2; i <= n; ++i) {
      dp[i][1] += dp[i - 1][0]; // a -> e
      
      dp[i][0] += dp[i - 1][1]; // e -> a
      dp[i][2] += dp[i - 1][1]; // e -> i
      
      for (int j = 0; j < 5; ++j) {
        if (j == 2) continue;
        dp[i][j] += dp[i - 1][2]; // i -> *
      }
      
      dp[i][2] += dp[i - 1][3]; // o -> i
      dp[i][4] += dp[i - 1][3]; // o -> u
      
      dp[i][0] += dp[i - 1][4]; // u -> a
      
      for (int j = 0; j < 5; ++j)
        dp[i][j] %= kMod;
    }
    return accumulate(begin(dp[n]), end(dp[n]), 0L) % kMod;
}

int main()
{
    int n = 5;
    int ans = countVowelPermutation(n);

    cout << ans << endl;

    return 0;
}