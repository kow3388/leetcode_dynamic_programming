#include <bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    bool row_o = false, col_o = false;
    vector<vector<int>> path(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == 0)
            {
                if(!row_o)
                    path[i][j] = 1;
                if(obstacleGrid[i][j] == 1)
                {
                    path[i][j] = INT_MIN;
                    row_o = true;
                }
            }
            if(j == 0)
            {
                if(!col_o)
                    path[i][j] = 1;
                if(obstacleGrid[i][j] == 1)
                {
                    path[i][j] = INT_MIN;
                    col_o = true;
                }
            }
            if(obstacleGrid[i][j] == 1)
                path[i][j] = INT_MIN;
        }
    
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            if(path[i][j] != INT_MIN)
            {
                if(path[i-1][j] == INT_MIN and path[i][j-1] == INT_MIN)
                    continue;
                else if(path[i-1][j] == INT_MIN and path[i][j-1] != INT_MIN)
                    path[i][j] = path[i][j-1];
                else if(path[i-1][j] != INT_MIN and path[i][j-1] == INT_MIN)
                    path[i][j] = path[i-1][j];
                else
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
    
    return path[m-1][n-1] > 0? path[m-1][n-1] : 0;
}

int main()
{
    vector<vector<int>> map = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int ans = uniquePathsWithObstacles(map);

    cout << ans << endl;

    return 0;
}