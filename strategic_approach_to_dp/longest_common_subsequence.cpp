#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    if(text1.length() < text2.length())
        swap(text1, text2);
    text1 = " " + text1;
    text2 = " " + text2;
    const int n = text1.length();
    const int m = text2.length();
    vector<vector<int>> len(m, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        len[0][i] = 0;
    for(int i = 0; i < m; i++)
        len[i][0] = 0;

    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            if(text2[i] == text1[j])
                len[i][j] = len[i-1][j-1] + 1;
            else
                len[i][j] = max(len[i-1][j], len[i][j-1]);
    
    return len[m-1][n-1];
}

int main()
{
    string text1 = "abc";
    string text2 = "def";
    int ans = longestCommonSubsequence(text1, text2);

    cout << ans << endl;

    return 0;
}