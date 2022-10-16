#include <bits/stdc++.h>

using namespace std;

//稍微看了一下其他人的想法
//想法是matrix的每個row紀錄最少的cost
//第一個row就是matrix的值
//之後的row就是自己的值 + min(左上, 正上, 右上)
int minFallingPathSum(vector<vector<int>> &matrix)
{
    const int m = matrix.size();
    const int n = matrix[0].size();

    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            if(j == 0)
                matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1]);
            else if(j == n-1)
                matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j-1]);
            else
                matrix[i][j] += min(min(matrix[i-1][j], matrix[i-1][j+1]),
                                    matrix[i-1][j-1]);
    }

    return *min_element(matrix[m-1].begin(), matrix[m-1].end());
}

int main()
{
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };
    int ans = minFallingPathSum(matrix);

    cout << ans << endl;

    return 0;
}