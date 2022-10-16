#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    const int n = cost.size();
    vector<int> min_cost(n, 0);
    min_cost[0] = cost[0];
    min_cost[1] = cost[1];

    for(int i = 2; i < n; i++)
        min_cost[i] = min(min_cost[i-1]+cost[i], min_cost[i-2]+cost[i]);
    
    return min(min_cost[n-2], min_cost[n-1]);
}

int main()
{
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int ans = minCostClimbingStairs(cost);

    cout << ans << endl;

    return 0;
}