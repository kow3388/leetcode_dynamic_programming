#include <bits/stdc++.h>

using namespace std;

int minCost(vector<vector<int>> &costs)
{
    const int n = costs.size();

    for(int i = 1; i < n; i++)
        for(int j = 0; j < 3; j++)
            switch(j)
            {
            case 0:
                costs[i][j] += min(costs[i-1][1], costs[i-1][2]);
                break;
            case 1:
                costs[i][j] += min(costs[i-1][0], costs[i-1][2]);
                break;
            case 2:
                costs[i][j] += min(costs[i-1][0], costs[i-1][1]);
                break;
            default:
                break;
            }
    
    return *min_element(costs[n-1].begin(), costs[n-1].end());
}

int main()
{
    vector<vector<int>> cost = {
        {17,2,17},
        {16,16,5},
        {14,3,19}
    };
    int ans = minCost(cost);

    cout << ans << endl;

    return 0;
}