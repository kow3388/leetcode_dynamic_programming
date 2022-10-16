#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    if(cost.size() == 2)
        return min(cost[0], cost[1]);
    else
    {
        int n = cost.size();
        vector<int> min_cost;
        min_cost.push_back(cost[0]);
        min_cost.push_back(min(min_cost[0] + cost[1], cost[1]));

        for(int i = 2; i < n; i++)
            min_cost.push_back(min(min_cost[i-1]+cost[i], min_cost[i-2]+cost[i]));

        int last = min_cost.back();
        min_cost.pop_back();
        int last2 = min_cost.back();

        return min(last, last2);
    }
}

int main()
{
    vector<int> cost = {10,15,20};
    int ans = minCostClimbingStairs(cost);

    cout << ans << endl;

    return 0;
}