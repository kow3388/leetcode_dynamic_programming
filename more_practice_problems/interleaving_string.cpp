#include <bits/stdc++.h>

using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    const int l1 = s1.length();
    const int l2 = s2.length();
    const int l3 = s3.length();

    if(l1 + l2 != l3)
        return false;

    //dp[i][j] => 表示s3[0:i+j]是不是由s1[i] + s2[j]組成
    vector<vector<int>> dp(l1+1, vector<int>(l2+1));
    dp[0][0] = true;

    for(int i = 0; i <= l1; i++)
        for(int j = 0; j <= l2; j++)
        {
            //有s1的字
            if(i > 0)
                //看最後一個字是不是s1的
                dp[i][j] |= dp[i-1][j] and (s1[i-1] == s3[i+j-1]);
            //有s2的字
            if(j > 0)
                //看最後一個字是不是s2的
                dp[i][j] |= dp[i][j-1] and (s2[j-1] == s3[i+j-1]);
        }

    return dp[l1][l2];
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool ans = isInterleave(s1, s2, s3);

    cout << ans << endl;

    return 0;
}