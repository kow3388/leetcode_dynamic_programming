#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> path(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
        path[i][0] = 1;

    for(int i = 0; i < m; i++)
        path[0][i] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            path[i][j] = path[i-1][j] + path[i][j-1];
    
    return path[n-1][m-1];
}

int main()
{
    int m = 3;
    int n = 7;
    int ans = uniquePaths(m, n);

    cout << ans << endl;

    return 0;
}