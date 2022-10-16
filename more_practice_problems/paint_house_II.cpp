#include <bits/stdc++.h>

using namespace std;

//如果用paint_house的方法會變成O(nm^2)
//但題目要求O(nm), 想不到
//紀錄最小值和次小值
int minCostII(vector<vector<int>> &costs)
{
    const int n = costs.size();
    const int m = costs[0].size();
    //最小值, 次小值, 最小值的index
    int min1 = 0, min2 = 0, idx = -1;

    for(int i = 0; i < n; i++)
    {
        //每層開始先設為無限大
        int m1 = INT_MAX, m2 = m1, id = -1;
        for(int j = 0; j < m; j++)
        {
            //如果目前的值和上一層的最小index相同，則加上層次小
            int cost = costs[i][j] + (j == idx? min2 : min1);
            //記錄這層最小和次小及最小index
            if(cost < m1)
            {
                m2 = m1;
                m1 = cost;
                id = j;
            }
            else if(cost < m2)
                m2 = cost;
        }
        min1 = m1;
        min2 = m2;
        idx = id;
    }

    return min1;
}

int main()
{
    vector<vector<int>> cost = {
        {1,5,3},
        {2,4,9},
    };
    int ans = minCostII(cost);

    cout << ans << endl;

    return 0;
}