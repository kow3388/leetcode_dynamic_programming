#include <bits/stdc++.h>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    const int row = matrix.size();
    const int col = matrix[0].size();
    int max_side = 0;
    vector<vector<int>> side_len(row, vector<int>(col, 0));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(matrix[i][j] == '1')
            {
                if(i == 0 or j == 0)
                    side_len[i][j] = 1;
                else
                    side_len[i][j] = min(min(side_len[i-1][j], side_len[i][j-1]),
                                         side_len[i-1][j-1]) + 1;

                max_side = max(max_side, side_len[i][j]);
            }
    
    return max_side*max_side;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int ans = maximalSquare(matrix);

    cout << ans << endl;

    return 0;
}